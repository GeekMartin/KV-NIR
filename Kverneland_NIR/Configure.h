#pragma once
#include "configDialogclass.h"

namespace Kverneland_NIR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;

	/// <summary>
	/// Summary for Configure
	/// </summary>
	public ref class Configure : public System::Windows::Forms::Form
	{


	public:
		Configure()
		{
			InitializeComponent();

			findPorts();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Configure()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  gpsPortSettingGroupBox;
	
	private: System::Windows::Forms::ComboBox^  gpsCOMPortBox;
	private: System::Windows::Forms::ComboBox^  gpsBaudRateBox;
	private: System::Windows::Forms::Label^  gpsCOMPortsLabel;
	private: System::Windows::Forms::Label^  gpsBaudRateLabel;
	private: System::Windows::Forms::ProgressBar^  gpsPortStatusBar;
	private: System::Windows::Forms::Label^  gpsPortStatusLabel;
	private: System::Windows::Forms::Button^  applyPortButton;


	private: System::IO::Ports::SerialPort^  configGpsReceiverSerialPort;
	private:

	private:


	private: System::Windows::Forms::Button^  refreshPorts;
	private: System::Windows::Forms::Label^  informationLabel;

	private: System::ComponentModel::IContainer^  components;

	
	
	//public: String ^gpsPortName;
	//public:	int ^gpsBaudRate;
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Configure::typeid));
			this->gpsPortSettingGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->gpsCOMPortBox = (gcnew System::Windows::Forms::ComboBox());
			this->gpsBaudRateBox = (gcnew System::Windows::Forms::ComboBox());
			this->gpsCOMPortsLabel = (gcnew System::Windows::Forms::Label());
			this->gpsBaudRateLabel = (gcnew System::Windows::Forms::Label());
			this->gpsPortStatusBar = (gcnew System::Windows::Forms::ProgressBar());
			this->gpsPortStatusLabel = (gcnew System::Windows::Forms::Label());
			this->applyPortButton = (gcnew System::Windows::Forms::Button());
			this->configGpsReceiverSerialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->refreshPorts = (gcnew System::Windows::Forms::Button());
			this->informationLabel = (gcnew System::Windows::Forms::Label());
			this->gpsPortSettingGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// gpsPortSettingGroupBox
			// 
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsCOMPortBox);
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsBaudRateBox);
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsCOMPortsLabel);
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsBaudRateLabel);
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsPortStatusBar);
			this->gpsPortSettingGroupBox->Controls->Add(this->gpsPortStatusLabel);
			this->gpsPortSettingGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->gpsPortSettingGroupBox->Location = System::Drawing::Point(36, 12);
			this->gpsPortSettingGroupBox->Name = L"gpsPortSettingGroupBox";
			this->gpsPortSettingGroupBox->Size = System::Drawing::Size(252, 152);
			this->gpsPortSettingGroupBox->TabIndex = 35;
			this->gpsPortSettingGroupBox->TabStop = false;
			this->gpsPortSettingGroupBox->Text = L"GPS Port Settings";
			// 
			// gpsCOMPortBox
			// 
			this->gpsCOMPortBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->gpsCOMPortBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsCOMPortBox->FormattingEnabled = true;
			this->gpsCOMPortBox->Location = System::Drawing::Point(116, 22);
			this->gpsCOMPortBox->Name = L"gpsCOMPortBox";
			this->gpsCOMPortBox->Size = System::Drawing::Size(121, 21);
			this->gpsCOMPortBox->TabIndex = 0;
			// 
			// gpsBaudRateBox
			// 
			this->gpsBaudRateBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->gpsBaudRateBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsBaudRateBox->FormattingEnabled = true;
			this->gpsBaudRateBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"9600", L"19200", L"38400", L"57600", L"115200" });
			this->gpsBaudRateBox->Location = System::Drawing::Point(116, 65);
			this->gpsBaudRateBox->Name = L"gpsBaudRateBox";
			this->gpsBaudRateBox->Size = System::Drawing::Size(121, 21);
			this->gpsBaudRateBox->TabIndex = 1;
			// 
			// gpsCOMPortsLabel
			// 
			this->gpsCOMPortsLabel->AutoSize = true;
			this->gpsCOMPortsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsCOMPortsLabel->Location = System::Drawing::Point(10, 22);
			this->gpsCOMPortsLabel->Name = L"gpsCOMPortsLabel";
			this->gpsCOMPortsLabel->Size = System::Drawing::Size(67, 13);
			this->gpsCOMPortsLabel->TabIndex = 2;
			this->gpsCOMPortsLabel->Text = L"COM Ports";
			// 
			// gpsBaudRateLabel
			// 
			this->gpsBaudRateLabel->AutoSize = true;
			this->gpsBaudRateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsBaudRateLabel->Location = System::Drawing::Point(10, 68);
			this->gpsBaudRateLabel->Name = L"gpsBaudRateLabel";
			this->gpsBaudRateLabel->Size = System::Drawing::Size(67, 13);
			this->gpsBaudRateLabel->TabIndex = 3;
			this->gpsBaudRateLabel->Text = L"Baud Rate";
			// 
			// gpsPortStatusBar
			// 
			this->gpsPortStatusBar->Location = System::Drawing::Point(116, 114);
			this->gpsPortStatusBar->Name = L"gpsPortStatusBar";
			this->gpsPortStatusBar->Size = System::Drawing::Size(121, 21);
			this->gpsPortStatusBar->TabIndex = 7;
			// 
			// gpsPortStatusLabel
			// 
			this->gpsPortStatusLabel->AutoSize = true;
			this->gpsPortStatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsPortStatusLabel->Location = System::Drawing::Point(7, 114);
			this->gpsPortStatusLabel->Name = L"gpsPortStatusLabel";
			this->gpsPortStatusLabel->Size = System::Drawing::Size(103, 13);
			this->gpsPortStatusLabel->TabIndex = 8;
			this->gpsPortStatusLabel->Text = L"Read to Connect";
			// 
			// applyPortButton
			// 
			this->applyPortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->applyPortButton->Location = System::Drawing::Point(98, 170);
			this->applyPortButton->Name = L"applyPortButton";
			this->applyPortButton->Size = System::Drawing::Size(104, 45);
			this->applyPortButton->TabIndex = 36;
			this->applyPortButton->Text = L"Apply";
			this->applyPortButton->UseVisualStyleBackColor = true;
			this->applyPortButton->Click += gcnew System::EventHandler(this, &Configure::applyPortButton_Click);
			// 
			// configGpsReceiverSerialPort
			// 
			this->configGpsReceiverSerialPort->ReadTimeout = 500;
			// 
			// refreshPorts
			// 
			this->refreshPorts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->refreshPorts->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"refreshPorts.Image")));
			this->refreshPorts->Location = System::Drawing::Point(330, 19);
			this->refreshPorts->Name = L"refreshPorts";
			this->refreshPorts->Size = System::Drawing::Size(34, 33);
			this->refreshPorts->TabIndex = 38;
			this->refreshPorts->UseVisualStyleBackColor = true;
			this->refreshPorts->Click += gcnew System::EventHandler(this, &Configure::refreshPorts_Click);
			// 
			// informationLabel
			// 
			this->informationLabel->AutoSize = true;
			this->informationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->informationLabel->Location = System::Drawing::Point(39, 230);
			this->informationLabel->Name = L"informationLabel";
			this->informationLabel->Size = System::Drawing::Size(0, 13);
			this->informationLabel->TabIndex = 39;
			// 
			// Configure
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(387, 235);
			this->Controls->Add(this->informationLabel);
			this->Controls->Add(this->refreshPorts);
			this->Controls->Add(this->applyPortButton);
			this->Controls->Add(this->gpsPortSettingGroupBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Configure";
			this->Text = L"Configurations";
			this->gpsPortSettingGroupBox->ResumeLayout(false);
			this->gpsPortSettingGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Find available ports
	private: void findPorts(void)
	{
		//get port names
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		//Clear the COM port boxes 
		this->gpsCOMPortBox->Items->Clear();

		//add sting array to combobox
		this->gpsCOMPortBox->Items->AddRange(objectArray);
	}

	private: System::Void refreshPorts_Click(System::Object^  sender, System::EventArgs^  e)
	{

		findPorts();
	}

	private: System::Void applyPortButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		if (this->gpsCOMPortBox->Text == String::Empty || this->gpsBaudRateBox->Text == String::Empty)
		{
			this->informationLabel->Text = "Please check GPS port settings";
		}
		else
		{
			String^ gpsPortName = gcnew configDialogclass->gpsPortName;
			this->informationLabel->Text = String::Empty;
			gpsPortName = gpsCOMPortBox->Text;
			//gpsBaudRate = Int32::Parse(this->gpsBaudRateBox->Text);
			gpsPortStatusBar->Value = 100;
		}
	}

	};
}
