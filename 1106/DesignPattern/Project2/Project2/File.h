#ifndef FILE_H
#define FILE_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "FileBase.h"


/*** ファイルクラス */
class File : public FileBase
{
public:
	/**
	 * コンストラクタ
	 * @param[in] _name 設定する名前
	 */
	File(LPCTSTR _name);

	/*** デストラクタ */
	virtual ~File();

	/**
	 * 名前の取得
	 * @return 名前
	 */
	virtual LPCTSTR GetName();

	/**
	 * サイズの取得
	 * @return サイズ
	 */
	virtual int GetSize();

	/**
	 * ファイルの追加
	 * @param[in] _pFile 追加するファイル
	 */
	virtual void Add(FileBase* _pFile);

	/*** データ出力 */
	virtual void Print(int _hierarchyNum = 0);

};


#endif // !FILE_H
