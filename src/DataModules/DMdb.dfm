object DataBaseModule: TDataBaseModule
  Height = 77
  Width = 149
  PixelsPerInch = 120
  object FDConnection: TFDConnection
    Params.Strings = (
      'Database=C:\Users\user\Desktop\db.db'
      'DriverID=SQLite')
  end
  object FDPhysSQLiteDriverLink: TFDPhysSQLiteDriverLink
    Left = 40
  end
  object FDQuery: TFDQuery
    Connection = FDConnection
    Left = 80
  end
end
