#ifndef FOLDER_H
#define FOLDER_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "FileBase.h"

#include <vector>


/*** フォルダクラス */
class Folder : public FileBase
{
public:
	/**
	 * コンストラクタ 
	 * @param[in] _name 設定する名前
	 */
	Folder(LPCTSTR _name);

	/*** デストラクタ */
	virtual ~Folder();

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

private:
	std::vector<FileBase*> m_pFiles;

};


#endif // !FOLDER_H
