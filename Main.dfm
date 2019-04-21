object RaskrForm: TRaskrForm
  Left = 110
  Top = 299
  Width = 638
  Height = 594
  Caption = #1056#1072#1089#1082#1088#1086#1081
  Color = clBtnFace
  Constraints.MinHeight = 594
  Constraints.MinWidth = 638
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    630
    560)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 64
    Width = 79
    Height = 13
    Caption = #1044#1083#1080#1085#1072'    '#1050#1086#1083'-'#1074#1086
  end
  object Label2: TLabel
    Left = 152
    Top = 8
    Width = 19
    Height = 13
    Caption = ' '#1084#1084
  end
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 91
    Height = 13
    Caption = #1044#1083#1080#1085#1072' '#1079#1072#1075#1086#1090#1086#1074#1082#1080':'
  end
  object Label4: TLabel
    Left = 192
    Top = 8
    Width = 71
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072' '#1087#1080#1083#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 296
    Top = 8
    Width = 19
    Height = 13
    Caption = ' '#1084#1084
  end
  object Label6: TLabel
    Left = 104
    Top = 64
    Width = 105
    Height = 13
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1088#1072#1089#1082#1088#1086#1103
  end
  object EditZag: TEdit
    Left = 104
    Top = 4
    Width = 49
    Height = 21
    TabOrder = 0
    Text = '6000'
  end
  object InTable: TMemo
    Left = 8
    Top = 80
    Width = 89
    Height = 473
    Anchors = [akLeft, akTop, akBottom]
    Lines.Strings = (
      '6000 10')
    ScrollBars = ssBoth
    TabOrder = 2
    WordWrap = False
  end
  object OutTable: TMemo
    Left = 104
    Top = 80
    Width = 521
    Height = 473
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'OutTable')
    ScrollBars = ssBoth
    TabOrder = 4
    WordWrap = False
  end
  object StartButton: TButton
    Left = 136
    Top = 32
    Width = 113
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1088#1072#1089#1082#1088#1086#1081
    TabOrder = 3
    OnClick = StartButtonClick
  end
  object EditCut: TEdit
    Left = 264
    Top = 4
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '5'
  end
  object InClearBt: TButton
    Left = 8
    Top = 32
    Width = 121
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1077' '#1074#1074#1086#1076#1072
    TabOrder = 6
    OnClick = InClearBtClick
  end
  object OutClearBt: TButton
    Left = 256
    Top = 32
    Width = 129
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1077' '#1074#1099#1074#1086#1076#1072
    TabOrder = 7
    OnClick = OutClearBtClick
  end
  object SaveButton: TButton
    Left = 392
    Top = 32
    Width = 65
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 5
    OnClick = SaveButtonClick
  end
  object SaveDialog1: TSaveDialog
    Left = 416
  end
end
