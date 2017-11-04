#ifndef FILEBASE_H
#define FILEBASE_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include <Windows.h>
#include <stdio.h>


/*** ファイル基底クラス */
class FileBase
{
public:
	/**
	 * コンストラクタ 
	 * @param[in] _name 設定する名前
	 */
	FileBase(LPCTSTR _name);

	/*** デストラクタ */
	virtual ~FileBase();

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

	/**
	 * データ出力 
	 * @param[in] _hierarchyNum 階層数
	 */
	virtual void Print(int _hierarchyNum = 0);

protected:
	LPCTSTR m_pName;	//!< 名前.
	int		m_Size;		//!< サイズ.

};


#endif // !FILEBASE_H
