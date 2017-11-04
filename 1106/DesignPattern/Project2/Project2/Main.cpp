//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "Folder.h"
#include "File.h"


void main()
{
	File file("file01");
	File file2("file02");
	File file3("file03");
	File file4("file04");
	File file5("file05");
	File file6("file06");

	Folder folder("folder01");
	Folder folder2("folder02");
	Folder folder3("folder03");

	folder.Add(&file);
	folder.Add(&file2);
	folder.Add(&folder2);
	folder.Add(&folder3);

	folder2.Add(&file3);

	folder3.Add(&file4);
	folder3.Add(&file5);
	folder3.Add(&file6);

	folder.Print();

	while (1);
}
