//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "Folder.h"


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
Folder::Folder(LPCTSTR _name) : 
	FileBase(_name)
{
}

Folder::~Folder()
{
}


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
LPCTSTR Folder::GetName()
{
	return m_pName;
}

int Folder::GetSize()
{
	return m_Size;
}

void Folder::Add(FileBase* _pFile)
{
	m_pFiles.push_back(_pFile);
	m_Size++;
}

void Folder::Print(int _hierarchyNum)
{
	// 階層の深さに応じてタブを追加.
	for (int i = 0; i < _hierarchyNum; i++)
	{
		printf("	");
	}

	printf("%8s - %s", "Folder", m_pName);
	for (unsigned int i = 0; i < m_pFiles.size(); i++)
	{
		printf("\n");
		m_pFiles[i]->Print(_hierarchyNum + 1);	// フォルダ内のオブジェクトすべて出力.
	}

	printf("\n");
}
