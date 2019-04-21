//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRaskrForm *RaskrForm;
//---------------------------------------------------------------------------

__fastcall TRaskrForm::TRaskrForm(TComponent* Owner)
        : TForm(Owner)
{
        EditZag->Text="6000";
        EditCut->Text="3";
        InTable->Clear();
        OutTable->Clear();
}

//---------------------------------------------------------------------------

void __fastcall TRaskrForm::StartButtonClick(TObject *Sender) //инициализация 
{
        int count = InTable->Lines->Count; //кол-во деталей
        int zag_L = StrToInt(EditZag->Text); //длина заготовки

        int cut = StrToInt(EditCut->Text); //толщина пилы
        
        Vector im1, im2; //

		
	    im1.init(count); //создаем 2 вектора передачей кол-ва деталей
        im2.init(count);
		
		
		//-------- Вставка из Smath.h --------- //
		
		int Vector::init(int x_count)
		{
			pM = new int [x_count]; //п-массив по кол-ву деталей
			if (pM == NULL) return 1; //вернуть 1, если массив NULL (защита?)
			count = x_count; //сохраняем внутри кол-во деталей
			flag_destr = true; //флаг детр TRUE
			return 0; //возвращаем 0
		}
		//--------- Вставка из Smath.h --------- //

		
		//запуск с проверкой на ошибку. Передаем 2 пустых массива, кол-во деталей, толщину пилы
        if (Get_Table(&im1,&im2,count,cut)!=true) 
            {
            ErrorMessage(1); //---ErrorCode---
            return;
            }
        
        //------MaxCode------

 	    ShTR ob;
        Matrix mR;
  	    ob.Init(&im1,&im2,zag_L);
	    ob.run();

        //------MaxCode------
        int summ=0;
        if (ob.get_matrix_raskroy(&mR)==1)
            {
            ErrorMessage(2); //---ErrorCode---
            return;
            }
        else
            {
            OutTable->Lines->Add("\tВ В О Д Н Ы Е   Д А Н Н Ы Е");
            OutTable->Lines->Add("");
            OutTable->Lines->Add("Длина заготовки: "+EditZag->Text+"мм"+'\t'+"Ширина пилы: "+EditCut->Text+"мм");
            OutTable->Lines->Add("");
            OutTable->Lines->Add("Длина\tКол-во");
            InTable->SelectAll();
            InTable->CopyToClipboard();
            OutTable->PasteFromClipboard();
            OutTable->Lines->Add("");
            OutTable->Lines->Add("\t\tР А С К Р О Й");
            String Line;
            Line="Палка\t";
            for(int x = 0; x < mR.countY-1; x++)
                {
                Line+="\t";
                }
            Line+="\tОстаток";
            OutTable->Lines->Add(Line);
            for (int y = 0; y < mR.countX; y++)
                {
                String Line;
                if (y<9)
                    Line="№0" +IntToStr(y+1)+": \t";
                else
                    Line="№" + IntToStr(y+1)+": \t";
                int sum=0;
                int count=0;
                for(int x = 0; x < mR.countY; x++)
                    if (mR[x][y]!=0)
                        {
                        Line+=IntToStr(mR[x][y]-cut)+"\t";
                        sum+=mR[x][y]-cut;
                        count+=1;
                        }
                    else
                        {
                        Line+="\t";
                        }
                summ+=sum;
                Line+=IntToStr(zag_L-sum-count*cut);
                OutTable->Lines->Add(Line);
                }
            }
            OutTable->Lines->Add("-------------------------------------------------------");
            double ClearPog=summ;
            ClearPog=RoundTo(ClearPog/1000, -2);
            double GrPog=mR.countX*zag_L;
            GrPog=RoundTo(GrPog/1000, -2);

            OutTable->Lines->Add("Чистый погонаж: "+FloatToStr(ClearPog)+" пм");
            OutTable->Lines->Add("Грязный погонаж: "+FloatToStr(GrPog)+" пм");
}

//---------------------------------------------------------------------------

bool TRaskrForm::Get_Table(Vector * pV1, Vector * pV2, int count, int cut) //вызов с передачей хз, кол-во заготовок, рез
{
        int zag = StrToInt(EditZag->Text); //длина заготовка из формы
        for (int row_count=0; row_count < count; row_count++) //проходим по заготовкам
            {

            String Zag_L ; //длина заготовки
            String Zag_C ; //кол-во заготовок
            String Row = InTable->Lines->Strings[row_count]; //берем всю строку с заготовкой
            int Length=Row.Length(); //длина строки с заготовкой
            if (Length!=1)
                {
                bool Flag=True; 								//ставим флаг "Да"
                for(int col = 1; col <= Length; col++) 			//парсим строку с заготовкой посимвольно
                    {
                    char temp = Row[col]; 						//берем символ
                      if (temp==' ' || temp=='\t' || temp=='-') //если это пробел или каретка или тире
                        if (Flag==False)                        //и если флаг "нет"
                            return false;						//возвращаем "нет"
                        else
                            Flag=False;							//иначе флаг "нет"
                    else
                        {
                        if(temp>'9' || temp < '0' || temp == ' ') return false;
                        if (Flag)
                            Zag_L+=temp;
                        else
                            Zag_C+=temp;
                        }
                    }
					
                    if (Zag_L=="")
                        return false;
                    else
                        if (StrToInt(Zag_L)<zag+1)
                        (*pV1)[row_count]=StrToInt(Zag_L)+cut;
                        else
                        	return false;
                    if (Zag_C=="")
                        return false;
                    else
                    	if (StrToInt(Zag_C)!=0)
                        (*pV2)[row_count]=StrToInt(Zag_C);
                        else
                        	return false;
                }
            else return false;
            }
return true;
}

//---------------------------------------------------------------------------

void TRaskrForm::ErrorMessage(int code)
{
  String ErrText;
  switch(code)
    {
    case 1: {ErrText="Ошибка в заполнении исходных данных\n";break;}
    case 2: {ErrText="Ошибка контрольной суммы\n";break;}
    }
  ShowMessage(ErrText);
  return;
}

//---------------------------------------------------------------------------

void __fastcall TRaskrForm::InClearBtClick(TObject *Sender)
{
    InTable->Clear();
}

//---------------------------------------------------------------------------

void __fastcall TRaskrForm::OutClearBtClick(TObject *Sender)
{
    OutTable->Clear();
}

//---------------------------------------------------------------------------

void __fastcall TRaskrForm::SaveButtonClick(TObject *Sender)
{
        //FILE *stream;

        SaveDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
        SaveDialog1->FilterIndex = 1;
	    SaveDialog1->Title = "Save File";
  		if (SaveDialog1->Execute())
                        {
                        OutTable->Lines->SaveToFile(SaveDialog1->FileName+".txt");
                        OutTable->Clear();
                        }

}
//---------------------------------------------------------------------------

void __fastcall TRaskrForm::Button1Click(TObject *Sender)
{
//CopyToclipboard();
}
//---------------------------------------------------------------------------

