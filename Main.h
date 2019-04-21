//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Math.hpp>
//#include "Smath.h"
#include "ShTR.h"
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TRaskrForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditZag;
        TMemo *InTable;
        TMemo *OutTable;
        TButton *StartButton;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *EditCut;
        TLabel *Label5;
        TButton *InClearBt;
        TButton *OutClearBt;
        TButton *SaveButton;
	TSaveDialog *SaveDialog1;
	TLabel *Label6;
        void __fastcall StartButtonClick(TObject *Sender);
        void __fastcall InClearBtClick(TObject *Sender);
        void __fastcall OutClearBtClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        
        __fastcall TRaskrForm(TComponent* Owner);
        bool Get_Table(Vector * pV1, Vector * pV2, int count, int cut);
        void ErrorMessage(int code);
        
};
//---------------------------------------------------------------------------
extern PACKAGE TRaskrForm *RaskrForm;
//---------------------------------------------------------------------------
#endif
