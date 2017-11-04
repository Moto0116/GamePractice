//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "File.h"


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
File::File(LPCTSTR _name) : 
	FileBase(_name)
{
}

File::~File()
{
}


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
LPCTSTR File::GetName()
{
	return m_pName;
}

int File::GetSize()
{
	return m_Size;
}

void File::Add(FileBase* _pFile)
{
	OutputDebugString("\nファイルには追加できません\n");
}

void File::Print(int _hierarchyNum)
{
	// 階層の深さに応じてタブを追加.
	for (int i = 0; i < _hierarchyNum; i++)
	{
		printf("	");
	}

	printf("%8s - %s", "File", m_pName);
}
