#include "MyForm.h"

using namespace SteganographyGUI;

[STAThreadAttribute]

int main(array<System::String ^> ^args) 
{
	//Windows Visual
	// 1 == true, 0 == false
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//main windows
	Application::Run(gcnew MyForm());

	//WHen program ends, return 0 to system, end window
	return 0;
}