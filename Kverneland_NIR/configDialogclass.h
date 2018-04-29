#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;

ref class configDialogclass
{
public: String ^gpsPortName;
public:	int ^gpsBaudRate;

public:
	configDialogclass();
};

