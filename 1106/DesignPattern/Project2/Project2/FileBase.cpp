//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "FileBase.h"


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
FileBase::FileBase(LPCTSTR _name) : 
	m_pName(_name),
	m_Size(1)
{
}

FileBase::~FileBase()
{
}


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
LPCTSTR FileBase::GetName()
{
	return m_pName;
}

int FileBase::GetSize()
{
	return m_Size;
}

void FileBase::Add(FileBase* _pFile)
{
}

void FileBase::Print(int _hierarchyNum)
{
	// 階層の深さに応じてタブを追加.
	for (int i = 0; i < _hierarchyNum; i++)
	{
		printf("	");
	}

	printf("%8s - %s", "FileBase", m_pName);
}
