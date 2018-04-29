#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

namespace Kverneland_NIR {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace System::Threading;
	

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();
			timer1->Start();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		//Global variables 
	
	private: unsigned int intLatitude;
	private: unsigned int intLatitude2;
	private: unsigned int intLongitude;
	private: unsigned int intLongitude2;
	private: unsigned int measurementNR = 1;

	private: SaveFileDialog^ saveDialog;
	private: StreamWriter^ writeToTheFile;
	private: String^ FilePath;

	private: System::IO::Ports::SerialPort^  gpsReceiverSerialPort;
	private: System::Windows::Forms::ComboBox^  gpsCOMPortBox;
	private: System::Windows::Forms::ComboBox^  gpsBaudRateBox;
	private: System::Windows::Forms::Label^  gpsCOMPortsLabel;
	private: System::Windows::Forms::Label^  gpsBaudRateLabel;
	private: System::Windows::Forms::Button^  openGPSPortButton;
	private: System::Windows::Forms::Button^  closeGPSPortButton;
	private: System::Windows::Forms::ProgressBar^  gpsPortStatusBar;
	private: System::Windows::Forms::Label^  gpsPortStatusLabel;
	private: System::Windows::Forms::TextBox^  gpsDataReciveTextBox;
	private: System::Windows::Forms::Button^  Read_port_button;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  Date_Time_Label;
	private: System::Windows::Forms::Label^  Latitude_label;
	private: System::Windows::Forms::TextBox^  latitude_Textbox;
	private: System::Windows::Forms::Label^  Longitude_label;
	private: System::Windows::Forms::TextBox^  longitude_Textbox;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TextBox^  dataHistoryTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ToolStrip^  mainToolStrip;
	private: System::Windows::Forms::ToolStripButton^  newToolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  openToolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripButton^  readDataToolStripButton;
	private: System::Windows::Forms::ToolTip^  readDataToolTip;
	private: System::Windows::Forms::ToolTip^  saveDataToolTip;
	private: System::Windows::Forms::ToolStripButton^  clearDataToolStripButton;
	private: System::IO::Ports::SerialPort^  tempSensorSerialPort;
	private: System::Windows::Forms::GroupBox^  gpsPortSettingGroupBox;
	private: System::Windows::Forms::Timer^  readTempTimer;
	private: System::Windows::Forms::ToolStripButton^  refreshPortsToolStrip;
	private: System::Windows::Forms::GroupBox^  tempGroupBox;
	private: System::Windows::Forms::ComboBox^  tempCOMPortComboBox;
	private: System::Windows::Forms::ComboBox^  tempBaudRateComboBox;
	private: System::Windows::Forms::Label^  tempCompPortsLabel;
	private: System::Windows::Forms::Label^  tempBaudRateLabel;
	private: System::Windows::Forms::ProgressBar^  tempPortStatusProgressBar;
	private: System::Windows::Forms::Label^  tempPortStatusLabel;
	private: System::Windows::Forms::Button^  closeTempPortButton;
	private: System::Windows::Forms::Button^  openTempPortButton;
	private: System::Windows::Forms::Label^  temperatureLabel;
	private: System::Windows::Forms::Button^  saveDataButton;
	private: System::Windows::Forms::Label^  tempHistoryBoxLabel;
	private: System::Windows::Forms::Label^  commentsLabel;
	private: System::Windows::Forms::NumericUpDown^  testNRnumericUpDown1;
	private: System::Windows::Forms::Label^  testNRBoxLabel;
	private: System::Windows::Forms::Label^  readErrorLabel;
	private: System::Windows::Forms::TextBox^  tempBox;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->gpsReceiverSerialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->gpsCOMPortBox = (gcnew System::Windows::Forms::ComboBox());
			this->gpsBaudRateBox = (gcnew System::Windows::Forms::ComboBox());
			this->gpsCOMPortsLabel = (gcnew System::Windows::Forms::Label());
			this->gpsBaudRateLabel = (gcnew System::Windows::Forms::Label());
			this->openGPSPortButton = (gcnew System::Windows::Forms::Button());
			this->closeGPSPortButton = (gcnew System::Windows::Forms::Button());
			this->gpsPortStatusBar = (gcnew System::Windows::Forms::ProgressBar());
			this->gpsPortStatusLabel = (gcnew System::Windows::Forms::Label());
			this->gpsDataReciveTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Read_port_button = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Date_Time_Label = (gcnew System::Windows::Forms::Label());
			this->Latitude_label = (gcnew System::Windows::Forms::Label());
			this->latitude_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->Longitude_label = (gcnew System::Windows::Forms::Label());
			this->longitude_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->dataHistoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->mainToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->newToolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->openToolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveToolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->readDataToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->clearDataToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->refreshPortsToolStrip = (gcnew System::Windows::Forms::ToolStripButton());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->readDataToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->saveDataButton = (gcnew System::Windows::Forms::Button());
			this->saveDataToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tempSensorSerialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->gpsPortSettingGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->readTempTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tempGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tempCOMPortComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tempBaudRateComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tempCompPortsLabel = (gcnew System::Windows::Forms::Label());
			this->tempBaudRateLabel = (gcnew System::Windows::Forms::Label());
			this->tempPortStatusProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->tempPortStatusLabel = (gcnew System::Windows::Forms::Label());
			this->closeTempPortButton = (gcnew System::Windows::Forms::Button());
			this->openTempPortButton = (gcnew System::Windows::Forms::Button());
			this->tempBox = (gcnew System::Windows::Forms::TextBox());
			this->temperatureLabel = (gcnew System::Windows::Forms::Label());
			this->tempHistoryBoxLabel = (gcnew System::Windows::Forms::Label());
			this->commentsLabel = (gcnew System::Windows::Forms::Label());
			this->testNRnumericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->testNRBoxLabel = (gcnew System::Windows::Forms::Label());
			this->readErrorLabel = (gcnew System::Windows::Forms::Label());
			this->mainToolStrip->SuspendLayout();
			this->gpsPortSettingGroupBox->SuspendLayout();
			this->tempGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testNRnumericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// gpsReceiverSerialPort
			// 
			this->gpsReceiverSerialPort->ReadBufferSize = 4000;
			this->gpsReceiverSerialPort->ReadTimeout = 500;
			// 
			// gpsCOMPortBox
			// 
			this->gpsCOMPortBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->gpsCOMPortBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->gpsCOMPortBox->FormattingEnabled = true;
			this->gpsCOMPortBox->Location = System::Drawing::Point(83, 19);
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
			this->gpsBaudRateBox->Location = System::Drawing::Point(83, 65);
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
			// openGPSPortButton
			// 
			this->openGPSPortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->openGPSPortButton->Location = System::Drawing::Point(607, 538);
			this->openGPSPortButton->Name = L"openGPSPortButton";
			this->openGPSPortButton->Size = System::Drawing::Size(104, 45);
			this->openGPSPortButton->TabIndex = 4;
			this->openGPSPortButton->Text = L"Open GPS";
			this->openGPSPortButton->UseVisualStyleBackColor = true;
			this->openGPSPortButton->Click += gcnew System::EventHandler(this, &MyForm::openGPSPortButton_Click);
			// 
			// closeGPSPortButton
			// 
			this->closeGPSPortButton->Enabled = false;
			this->closeGPSPortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->closeGPSPortButton->Location = System::Drawing::Point(728, 539);
			this->closeGPSPortButton->Name = L"closeGPSPortButton";
			this->closeGPSPortButton->Size = System::Drawing::Size(104, 45);
			this->closeGPSPortButton->TabIndex = 5;
			this->closeGPSPortButton->Text = L"Close GPS";
			this->closeGPSPortButton->UseVisualStyleBackColor = true;
			this->closeGPSPortButton->Click += gcnew System::EventHandler(this, &MyForm::closeGPSPortButton_Click);
			// 
			// gpsPortStatusBar
			// 
			this->gpsPortStatusBar->Location = System::Drawing::Point(83, 110);
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
			this->gpsPortStatusLabel->Size = System::Drawing::Size(70, 13);
			this->gpsPortStatusLabel->TabIndex = 8;
			this->gpsPortStatusLabel->Text = L"Port Status";
			// 
			// gpsDataReciveTextBox
			// 
			this->gpsDataReciveTextBox->Enabled = false;
			this->gpsDataReciveTextBox->Location = System::Drawing::Point(44, 596);
			this->gpsDataReciveTextBox->MaxLength = 200;
			this->gpsDataReciveTextBox->Multiline = true;
			this->gpsDataReciveTextBox->Name = L"gpsDataReciveTextBox";
			this->gpsDataReciveTextBox->ReadOnly = true;
			this->gpsDataReciveTextBox->Size = System::Drawing::Size(475, 24);
			this->gpsDataReciveTextBox->TabIndex = 9;
			this->gpsDataReciveTextBox->Text = L"Recived GPS Data";
			this->gpsDataReciveTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Read_port_button
			// 
			this->Read_port_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Read_port_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Read_port_button.Image")));
			this->Read_port_button->Location = System::Drawing::Point(723, 281);
			this->Read_port_button->Name = L"Read_port_button";
			this->Read_port_button->Size = System::Drawing::Size(79, 71);
			this->Read_port_button->TabIndex = 10;
			this->readDataToolTip->SetToolTip(this->Read_port_button, L"Read Data");
			this->Read_port_button->UseVisualStyleBackColor = true;
			this->Read_port_button->Click += gcnew System::EventHandler(this, &MyForm::Read_port_button_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// Date_Time_Label
			// 
			this->Date_Time_Label->AutoSize = true;
			this->Date_Time_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Date_Time_Label->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Date_Time_Label->Location = System::Drawing::Point(881, 607);
			this->Date_Time_Label->Name = L"Date_Time_Label";
			this->Date_Time_Label->Size = System::Drawing::Size(34, 13);
			this->Date_Time_Label->TabIndex = 11;
			this->Date_Time_Label->Text = L"Time";
			// 
			// Latitude_label
			// 
			this->Latitude_label->AutoSize = true;
			this->Latitude_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Latitude_label->Location = System::Drawing::Point(603, 178);
			this->Latitude_label->Name = L"Latitude_label";
			this->Latitude_label->Size = System::Drawing::Size(75, 20);
			this->Latitude_label->TabIndex = 12;
			this->Latitude_label->Text = L"Latitude";
			// 
			// latitude_Textbox
			// 
			this->latitude_Textbox->Enabled = false;
			this->latitude_Textbox->Font = (gcnew System::Drawing::Font(L"BankGothic Lt BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->latitude_Textbox->Location = System::Drawing::Point(723, 132);
			this->latitude_Textbox->Name = L"latitude_Textbox";
			this->latitude_Textbox->ReadOnly = true;
			this->latitude_Textbox->Size = System::Drawing::Size(163, 24);
			this->latitude_Textbox->TabIndex = 13;
			this->latitude_Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Longitude_label
			// 
			this->Longitude_label->AutoSize = true;
			this->Longitude_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->Longitude_label->Location = System::Drawing::Point(603, 132);
			this->Longitude_label->Name = L"Longitude_label";
			this->Longitude_label->Size = System::Drawing::Size(89, 20);
			this->Longitude_label->TabIndex = 14;
			this->Longitude_label->Text = L"Longitude";
			// 
			// longitude_Textbox
			// 
			this->longitude_Textbox->Enabled = false;
			this->longitude_Textbox->Font = (gcnew System::Drawing::Font(L"BankGothic Lt BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->longitude_Textbox->Location = System::Drawing::Point(723, 174);
			this->longitude_Textbox->Name = L"longitude_Textbox";
			this->longitude_Textbox->ReadOnly = true;
			this->longitude_Textbox->Size = System::Drawing::Size(163, 24);
			this->longitude_Textbox->TabIndex = 15;
			this->longitude_Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dataHistoryTextBox
			// 
			this->dataHistoryTextBox->Location = System::Drawing::Point(12, 67);
			this->dataHistoryTextBox->MaxLength = 250000;
			this->dataHistoryTextBox->Multiline = true;
			this->dataHistoryTextBox->Name = L"dataHistoryTextBox";
			this->dataHistoryTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->dataHistoryTextBox->Size = System::Drawing::Size(574, 513);
			this->dataHistoryTextBox->TabIndex = 19;
			this->dataHistoryTextBox->WordWrap = false;
			this->dataHistoryTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::dataHistoryTextBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Nr";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(74, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Latitude";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(170, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Longitude";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(359, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Time";
			// 
			// mainToolStrip
			// 
			this->mainToolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->mainToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->newToolStripButton1,
					this->openToolStripButton1, this->saveToolStripButton1, this->toolStripSeparator, this->readDataToolStripButton, this->clearDataToolStripButton,
					this->refreshPortsToolStrip
			});
			this->mainToolStrip->Location = System::Drawing::Point(0, 0);
			this->mainToolStrip->Name = L"mainToolStrip";
			this->mainToolStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->mainToolStrip->Size = System::Drawing::Size(1075, 25);
			this->mainToolStrip->TabIndex = 25;
			this->mainToolStrip->Text = L"mainToolStrip";
			// 
			// newToolStripButton1
			// 
			this->newToolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->newToolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newToolStripButton1.Image")));
			this->newToolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripButton1->Name = L"newToolStripButton1";
			this->newToolStripButton1->Size = System::Drawing::Size(23, 22);
			this->newToolStripButton1->Text = L"&New";
			this->newToolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::newToolStripButton1_Click);
			// 
			// openToolStripButton1
			// 
			this->openToolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openToolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripButton1.Image")));
			this->openToolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripButton1->Name = L"openToolStripButton1";
			this->openToolStripButton1->Size = System::Drawing::Size(23, 22);
			this->openToolStripButton1->Text = L"&Open";
			this->openToolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::openToolStripButton1_Click);
			// 
			// saveToolStripButton1
			// 
			this->saveToolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveToolStripButton1.Image")));
			this->saveToolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton1->Name = L"saveToolStripButton1";
			this->saveToolStripButton1->Size = System::Drawing::Size(23, 22);
			this->saveToolStripButton1->Text = L"&Save";
			this->saveToolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripButton1_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(6, 25);
			// 
			// readDataToolStripButton
			// 
			this->readDataToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->readDataToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"readDataToolStripButton.Image")));
			this->readDataToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->readDataToolStripButton->Name = L"readDataToolStripButton";
			this->readDataToolStripButton->Size = System::Drawing::Size(23, 22);
			this->readDataToolStripButton->Text = L"&Read Data";
			this->readDataToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::readDataToolStripButton_Click);
			// 
			// clearDataToolStripButton
			// 
			this->clearDataToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->clearDataToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearDataToolStripButton.Image")));
			this->clearDataToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->clearDataToolStripButton->Name = L"clearDataToolStripButton";
			this->clearDataToolStripButton->Size = System::Drawing::Size(23, 22);
			this->clearDataToolStripButton->Text = L"Clear Data";
			this->clearDataToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::clearDataToolStripButton_Click);
			// 
			// refreshPortsToolStrip
			// 
			this->refreshPortsToolStrip->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->refreshPortsToolStrip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"refreshPortsToolStrip.Image")));
			this->refreshPortsToolStrip->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->refreshPortsToolStrip->Name = L"refreshPortsToolStrip";
			this->refreshPortsToolStrip->Size = System::Drawing::Size(23, 22);
			this->refreshPortsToolStrip->Text = L"Refresh";
			this->refreshPortsToolStrip->Click += gcnew System::EventHandler(this, &MyForm::refreshPortsToolStrip_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveDataButton
			// 
			this->saveDataButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->saveDataButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveDataButton.Image")));
			this->saveDataButton->Location = System::Drawing::Point(807, 281);
			this->saveDataButton->Name = L"saveDataButton";
			this->saveDataButton->Size = System::Drawing::Size(79, 71);
			this->saveDataButton->TabIndex = 42;
			this->saveDataToolTip->SetToolTip(this->saveDataButton, L"Save Data ");
			this->saveDataButton->UseVisualStyleBackColor = true;
			this->saveDataButton->Click += gcnew System::EventHandler(this, &MyForm::saveDataButton_Click);
			// 
			// tempSensorSerialPort
			// 
			this->tempSensorSerialPort->ReadTimeout = 500;
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
			this->gpsPortSettingGroupBox->Location = System::Drawing::Point(607, 376);
			this->gpsPortSettingGroupBox->Name = L"gpsPortSettingGroupBox";
			this->gpsPortSettingGroupBox->Size = System::Drawing::Size(225, 156);
			this->gpsPortSettingGroupBox->TabIndex = 34;
			this->gpsPortSettingGroupBox->TabStop = false;
			this->gpsPortSettingGroupBox->Text = L"GPS Port Settings";
			// 
			// readTempTimer
			// 
			this->readTempTimer->Tick += gcnew System::EventHandler(this, &MyForm::readTempTimer_Tick);
			// 
			// tempGroupBox
			// 
			this->tempGroupBox->Controls->Add(this->tempCOMPortComboBox);
			this->tempGroupBox->Controls->Add(this->tempBaudRateComboBox);
			this->tempGroupBox->Controls->Add(this->tempCompPortsLabel);
			this->tempGroupBox->Controls->Add(this->tempBaudRateLabel);
			this->tempGroupBox->Controls->Add(this->tempPortStatusProgressBar);
			this->tempGroupBox->Controls->Add(this->tempPortStatusLabel);
			this->tempGroupBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->tempGroupBox->Location = System::Drawing::Point(838, 376);
			this->tempGroupBox->Name = L"tempGroupBox";
			this->tempGroupBox->Size = System::Drawing::Size(225, 156);
			this->tempGroupBox->TabIndex = 35;
			this->tempGroupBox->TabStop = false;
			this->tempGroupBox->Text = L"Temp Port Settings";
			// 
			// tempCOMPortComboBox
			// 
			this->tempCOMPortComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->tempCOMPortComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->tempCOMPortComboBox->FormattingEnabled = true;
			this->tempCOMPortComboBox->Location = System::Drawing::Point(83, 19);
			this->tempCOMPortComboBox->Name = L"tempCOMPortComboBox";
			this->tempCOMPortComboBox->Size = System::Drawing::Size(121, 21);
			this->tempCOMPortComboBox->TabIndex = 0;
			// 
			// tempBaudRateComboBox
			// 
			this->tempBaudRateComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->tempBaudRateComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->tempBaudRateComboBox->FormattingEnabled = true;
			this->tempBaudRateComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"9600", L"19200", L"38400", L"57600",
					L"115200"
			});
			this->tempBaudRateComboBox->Location = System::Drawing::Point(83, 65);
			this->tempBaudRateComboBox->Name = L"tempBaudRateComboBox";
			this->tempBaudRateComboBox->Size = System::Drawing::Size(121, 21);
			this->tempBaudRateComboBox->TabIndex = 1;
			// 
			// tempCompPortsLabel
			// 
			this->tempCompPortsLabel->AutoSize = true;
			this->tempCompPortsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->tempCompPortsLabel->Location = System::Drawing::Point(10, 22);
			this->tempCompPortsLabel->Name = L"tempCompPortsLabel";
			this->tempCompPortsLabel->Size = System::Drawing::Size(67, 13);
			this->tempCompPortsLabel->TabIndex = 2;
			this->tempCompPortsLabel->Text = L"COM Ports";
			// 
			// tempBaudRateLabel
			// 
			this->tempBaudRateLabel->AutoSize = true;
			this->tempBaudRateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->tempBaudRateLabel->Location = System::Drawing::Point(10, 68);
			this->tempBaudRateLabel->Name = L"tempBaudRateLabel";
			this->tempBaudRateLabel->Size = System::Drawing::Size(67, 13);
			this->tempBaudRateLabel->TabIndex = 3;
			this->tempBaudRateLabel->Text = L"Baud Rate";
			// 
			// tempPortStatusProgressBar
			// 
			this->tempPortStatusProgressBar->Location = System::Drawing::Point(83, 110);
			this->tempPortStatusProgressBar->Name = L"tempPortStatusProgressBar";
			this->tempPortStatusProgressBar->Size = System::Drawing::Size(121, 21);
			this->tempPortStatusProgressBar->TabIndex = 7;
			// 
			// tempPortStatusLabel
			// 
			this->tempPortStatusLabel->AutoSize = true;
			this->tempPortStatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->tempPortStatusLabel->Location = System::Drawing::Point(7, 114);
			this->tempPortStatusLabel->Name = L"tempPortStatusLabel";
			this->tempPortStatusLabel->Size = System::Drawing::Size(70, 13);
			this->tempPortStatusLabel->TabIndex = 8;
			this->tempPortStatusLabel->Text = L"Port Status";
			// 
			// closeTempPortButton
			// 
			this->closeTempPortButton->Enabled = false;
			this->closeTempPortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->closeTempPortButton->Location = System::Drawing::Point(959, 539);
			this->closeTempPortButton->Name = L"closeTempPortButton";
			this->closeTempPortButton->Size = System::Drawing::Size(104, 45);
			this->closeTempPortButton->TabIndex = 37;
			this->closeTempPortButton->Text = L"Close Temp";
			this->closeTempPortButton->UseVisualStyleBackColor = true;
			this->closeTempPortButton->Click += gcnew System::EventHandler(this, &MyForm::closeTempPortButton_Click);
			// 
			// openTempPortButton
			// 
			this->openTempPortButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->openTempPortButton->Location = System::Drawing::Point(838, 539);
			this->openTempPortButton->Name = L"openTempPortButton";
			this->openTempPortButton->Size = System::Drawing::Size(104, 45);
			this->openTempPortButton->TabIndex = 36;
			this->openTempPortButton->Text = L"Open Temp";
			this->openTempPortButton->UseVisualStyleBackColor = true;
			this->openTempPortButton->Click += gcnew System::EventHandler(this, &MyForm::openTempPortButton_Click);
			// 
			// tempBox
			// 
			this->tempBox->Enabled = false;
			this->tempBox->Font = (gcnew System::Drawing::Font(L"BankGothic Lt BT", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tempBox->Location = System::Drawing::Point(723, 214);
			this->tempBox->Name = L"tempBox";
			this->tempBox->ReadOnly = true;
			this->tempBox->Size = System::Drawing::Size(163, 41);
			this->tempBox->TabIndex = 40;
			this->tempBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// temperatureLabel
			// 
			this->temperatureLabel->AutoSize = true;
			this->temperatureLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->temperatureLabel->Location = System::Drawing::Point(603, 227);
			this->temperatureLabel->Name = L"temperatureLabel";
			this->temperatureLabel->Size = System::Drawing::Size(111, 20);
			this->temperatureLabel->TabIndex = 41;
			this->temperatureLabel->Text = L"Temperature";
			// 
			// tempHistoryBoxLabel
			// 
			this->tempHistoryBoxLabel->AutoSize = true;
			this->tempHistoryBoxLabel->Location = System::Drawing::Point(257, 48);
			this->tempHistoryBoxLabel->Name = L"tempHistoryBoxLabel";
			this->tempHistoryBoxLabel->Size = System::Drawing::Size(34, 13);
			this->tempHistoryBoxLabel->TabIndex = 43;
			this->tempHistoryBoxLabel->Text = L"Temp";
			// 
			// commentsLabel
			// 
			this->commentsLabel->AutoSize = true;
			this->commentsLabel->Location = System::Drawing::Point(481, 48);
			this->commentsLabel->Name = L"commentsLabel";
			this->commentsLabel->Size = System::Drawing::Size(59, 13);
			this->commentsLabel->TabIndex = 44;
			this->commentsLabel->Text = L"Comments ";
			// 
			// testNRnumericUpDown1
			// 
			this->testNRnumericUpDown1->Font = (gcnew System::Drawing::Font(L"BankGothic Lt BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->testNRnumericUpDown1->Location = System::Drawing::Point(723, 87);
			this->testNRnumericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->testNRnumericUpDown1->Name = L"testNRnumericUpDown1";
			this->testNRnumericUpDown1->Size = System::Drawing::Size(163, 24);
			this->testNRnumericUpDown1->TabIndex = 45;
			this->testNRnumericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->testNRnumericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->testNRnumericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::testNRnumericUpDown1_ValueChanged);
			// 
			// testNRBoxLabel
			// 
			this->testNRBoxLabel->AutoSize = true;
			this->testNRBoxLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->testNRBoxLabel->Location = System::Drawing::Point(603, 91);
			this->testNRBoxLabel->Name = L"testNRBoxLabel";
			this->testNRBoxLabel->Size = System::Drawing::Size(67, 20);
			this->testNRBoxLabel->TabIndex = 46;
			this->testNRBoxLabel->Text = L"Test Nr";
			// 
			// readErrorLabel
			// 
			this->readErrorLabel->AutoSize = true;
			this->readErrorLabel->Font = (gcnew System::Drawing::Font(L"BankGothic Lt BT", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->readErrorLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->readErrorLabel->Location = System::Drawing::Point(682, 263);
			this->readErrorLabel->Name = L"readErrorLabel";
			this->readErrorLabel->Size = System::Drawing::Size(0, 16);
			this->readErrorLabel->TabIndex = 47;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1075, 632);
			this->Controls->Add(this->readErrorLabel);
			this->Controls->Add(this->testNRBoxLabel);
			this->Controls->Add(this->testNRnumericUpDown1);
			this->Controls->Add(this->commentsLabel);
			this->Controls->Add(this->tempHistoryBoxLabel);
			this->Controls->Add(this->saveDataButton);
			this->Controls->Add(this->temperatureLabel);
			this->Controls->Add(this->tempBox);
			this->Controls->Add(this->closeTempPortButton);
			this->Controls->Add(this->openTempPortButton);
			this->Controls->Add(this->tempGroupBox);
			this->Controls->Add(this->gpsPortSettingGroupBox);
			this->Controls->Add(this->mainToolStrip);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataHistoryTextBox);
			this->Controls->Add(this->longitude_Textbox);
			this->Controls->Add(this->Longitude_label);
			this->Controls->Add(this->latitude_Textbox);
			this->Controls->Add(this->Latitude_label);
			this->Controls->Add(this->Date_Time_Label);
			this->Controls->Add(this->Read_port_button);
			this->Controls->Add(this->gpsDataReciveTextBox);
			this->Controls->Add(this->closeGPSPortButton);
			this->Controls->Add(this->openGPSPortButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L" Kverneland NIR Test 0.1.3";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->mainToolStrip->ResumeLayout(false);
			this->mainToolStrip->PerformLayout();
			this->gpsPortSettingGroupBox->ResumeLayout(false);
			this->gpsPortSettingGroupBox->PerformLayout();
			this->tempGroupBox->ResumeLayout(false);
			this->tempGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->testNRnumericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Find available ports
private: void findPorts(void)
{
	array<Object^>^ objectArray = SerialPort::GetPortNames();

	//Clear the GPS and Temp COM comboBoxes 
	this->gpsCOMPortBox->Items->Clear();
	this->tempCOMPortComboBox->Items->Clear();

	//add sting array (founded ports) to the comboboxes
	this->gpsCOMPortBox->Items->AddRange(objectArray);
	this->tempCOMPortComboBox->Items->AddRange(objectArray);
}

	//Open GPS COM Port Button 
private: System::Void openGPSPortButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Clear the box what shows GPS raw data 
	this->gpsDataReciveTextBox->Text = String::Empty;

	//If port settings are not selected, show the message
	if (this->gpsCOMPortBox->Text == String::Empty || this->gpsBaudRateBox->Text == String::Empty)
	{
		this->gpsDataReciveTextBox->Text = "Please check the GPS port settings";
	}
	//If port settings are selected, open the port
	else
	{
		try
		{
			//Make sure that the GPS port isn't open, if not opened, then open the GPS port
			if (!this->gpsReceiverSerialPort->IsOpen)
			{
				this->gpsReceiverSerialPort->PortName = this->gpsCOMPortBox->Text;
				this->gpsReceiverSerialPort->BaudRate = Int32::Parse(this->gpsBaudRateBox->Text);
				this->gpsReceiverSerialPort->Open();
				this->gpsPortStatusBar->Value = 100;
				this->openGPSPortButton->Enabled = false;
				this->closeGPSPortButton->Enabled = true;
				this->gpsDataReciveTextBox->Text = "GPS Port Opened Successfully";
			}
			else
				this->gpsDataReciveTextBox->Text = "Close the GPS port first";
		}
		catch (UnauthorizedAccessException^)
		{
			this->gpsDataReciveTextBox->Text = "UnauthorizedAccess";
		}
	}
}

		 //Close GPS COM Port Button 
private: System::Void closeGPSPortButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Close serial port
	this->gpsReceiverSerialPort->Close();
	//Update progress bar
	this->gpsPortStatusBar->Value = 0;
	//Enable read button
	this->openGPSPortButton->Enabled = true;
	this->closeGPSPortButton->Enabled = false;

	this->gpsDataReciveTextBox->Text = "GPS Port Closed Successfully";
}

		 //Open Temp COM Port
private: System::Void openTempPortButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Clear raw GPS data box
	this->gpsDataReciveTextBox->Text = String::Empty;

	//If port settings are not selected, show the message
	if (this->tempCOMPortComboBox->Text == String::Empty || this->tempBaudRateComboBox->Text == String::Empty)
	{
		this->gpsDataReciveTextBox->Text = "Please check the TEMP port settings";
	}

	else
	{
		try
		{
			//Make sure port isn't open
			if (!this->tempSensorSerialPort->IsOpen)
			{
				this->tempSensorSerialPort->PortName = this->tempCOMPortComboBox->Text;
				this->tempSensorSerialPort->BaudRate = Int32::Parse(this->tempBaudRateComboBox->Text);
				this->tempSensorSerialPort->Open();
				this->tempPortStatusProgressBar->Value = 100;
				this->openTempPortButton->Enabled = false;
				this->closeTempPortButton->Enabled = true;
				readTempTimer->Start();
				this->gpsDataReciveTextBox->Text = "TEMP Port Opened Successfully";
			}
			else
				this->gpsDataReciveTextBox->Text = " Close the TEMP port first";
		}
		catch (UnauthorizedAccessException^)
		{
			this->gpsDataReciveTextBox->Text = "UnauthorizedAccess";
		}
	}
}


		 //Close Temp COM Port
private: System::Void closeTempPortButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Close serial port
	this->tempSensorSerialPort->Close();
	//Update progress bar
	this->tempBox->Text = String::Empty;
	this->tempPortStatusProgressBar->Value = 0;
	//Enable read button
	this->openTempPortButton->Enabled = true;
	this->closeTempPortButton->Enabled = false;

	this->gpsDataReciveTextBox->Text = "TEMP Port Closed Successfully";
}


//READ GPS and Temp sensor data + current time. 
private: System::Void Read_port_button_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	String^ receivedRawData;

	testNRnumericUpDown1->Value = measurementNR;


	//Chech if port is ready for reading 
	if (this->gpsReceiverSerialPort->IsOpen)
	{
		//Clear the text in the GPS Recive Box
		this->gpsDataReciveTextBox->Text = String::Empty;
		//Clear the text in the Latitude Textbox
		this->latitude_Textbox->Text = String::Empty;
		//Clear the text in the Longitude Textbox
		this->longitude_Textbox->Text = String::Empty;
		// Clear received data buffer
		this->gpsReceiverSerialPort->DiscardInBuffer();

		try
		{	//Read GPS data 3 times, to decrease corrupted data % 
			for (int n = 0; n <= 2; n = n + 1)
			{
				receivedRawData = this->gpsReceiverSerialPort->ReadLine();
			}

			this->gpsDataReciveTextBox->Text = receivedRawData;

			if (gpsDataReciveTextBox->Text->Length > 70)
			{
				String^ GPS_data = gpsDataReciveTextBox->Text;

				// Separate Latitude from GPS data 
				String^ stringLatitude = GPS_data->Substring(17, 4);
				String ^ stringLatitude2 = GPS_data->Substring(22, 7);
				// Separate Longitude from GPS data 
				String^ stringLongitude = GPS_data->Substring(33, 4);
				String^ stringLongitude2 = GPS_data->Substring(38, 7);

				//Output Latitude to the latitude textbox
				this->latitude_Textbox->Text = stringLatitude + "." + stringLatitude2;
				//Output Latitude to the latitude textbox
				this->longitude_Textbox->Text = stringLongitude + "." + stringLongitude2;

				//insert reading data to the data history box
				this->dataHistoryTextBox->Text += measurementNR + ";\t";
				this->dataHistoryTextBox->Text += stringLatitude + "." + stringLatitude2 + ";\t";
				this->dataHistoryTextBox->Text += stringLongitude + "." + stringLongitude2 + ";\t";
				this->dataHistoryTextBox->Text += tempBox->Text + ";\t         ";
				this->dataHistoryTextBox->Text += DateTime::Now + ";\t\t\t\t;\r\n";
				readErrorLabel->Text = " ";
				measurementNR++;
			}
			else
			{
				readErrorLabel->Text = "Corrupted Data, take a new test ";
			}
		}
		// Give user know about read timeout "500ms"
		catch (TimeoutException^)
		{
			this->gpsDataReciveTextBox->Text = "Timeout Exeption";
		}
	}
	else 
	{
		this->gpsDataReciveTextBox->Text = "GPS Port is not Opened";
	}
}

//Get date and time from PC 
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	DateTime datetime = DateTime::Now;
	this->Date_Time_Label->Text = datetime.ToString();

}


//Clear data history text box
private: System::Void clearDataHistoryBox_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->dataHistoryTextBox->Clear();
	this->gpsDataReciveTextBox->Text = "Data Cleared Successfully";
}

//Save NEW document button on the toolstrip
private: System::Void newToolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
{

	saveDialog = gcnew SaveFileDialog();
	saveDialog->Filter = "CSV (Comma delimited) (*.csv)|*.csv|Text File (*.txt)|*.txt|All files (*.*)|*.*";
	saveDialog->FilterIndex = 1;
	saveDialog->FileName = "Kverneland Test Day 1";
	saveDialog->RestoreDirectory = true;
	
	if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		try
		{
			writeToTheFile = gcnew StreamWriter(saveDialog->OpenFile());
			//Output first line
			writeToTheFile->WriteLine(dataHistoryTextBox->Text);
			writeToTheFile->Close();
			FilePath = saveDialog->FileName;
			MessageBox::Show(FilePath, "File saved to ");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString(), "File is in use by another program");
		}

	}
}

// Save the data to the File 
private: System::Void saveToolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//If no filepath, got to -> create new file. 
	if (FilePath == nullptr)
	{
		newToolStripButton1->PerformClick();
	}

	else
	{
		try
		{
			writeToTheFile = gcnew StreamWriter(saveDialog->OpenFile());
			writeToTheFile->WriteLine(dataHistoryTextBox->Text);
			writeToTheFile->Close();
			MessageBox::Show("Data saved successfully", "Save");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString(),"File is in use by another program" );
		}
	}

}

//Open document button on the toolstrip
private: System::Void openToolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	openFileDialog1->Filter = "CSV (Comma delimited) (*.csv)|*.csv|Text File (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		try 
		{
			System::IO::StreamReader ^ readOpenedFiledata = gcnew
			System::IO::StreamReader(openFileDialog1->FileName);
			dataHistoryTextBox->Text = readOpenedFiledata->ReadToEnd();
			readOpenedFiledata->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString(), "File is in use by another program");
		}

	}
}

//Read GPS data button on the toolstrip
private: System::Void readDataToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Read_port_button->PerformClick();
}

//Clear data button on the toolstrip
private: System::Void clearDataToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->dataHistoryTextBox->Clear();
	this->gpsDataReciveTextBox->Text = "Data Cleared Successfully";
}


//Refresh COM Porst 
private: System::Void refreshPortsToolStrip_Click(System::Object^  sender, System::EventArgs^  e) 
{
	findPorts();
}

//Read temperature every second and show the time on the form. 
private: System::Void readTempTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if (this->tempSensorSerialPort->IsOpen)
	{
		try
		{
			String ^tempReadData = this->tempSensorSerialPort->ReadExisting();
			if (tempReadData != String::Empty)
			{
				tempBox->Text = tempReadData;
				tempBox->Text += " C";
			}
		}
		catch (TimeoutException^)
		{
			this->gpsDataReciveTextBox->Text = "Temp Timeout Exeption";
		}
	}
}

//Save data button == save toolstripe button, same function 
private: System::Void saveDataButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	saveToolStripButton1->PerformClick();
}

//Change Test nr manualy if needed.  
private: System::Void testNRnumericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	int testNRValueInt = System::Convert::ToInt32(testNRnumericUpDown1->Value);
	measurementNR = testNRValueInt ;
}


//Ask permission to close the application
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
	//Pressing YEs button close the application 
	if (MessageBox::Show("Are you sure ?", "Kverneland NIR Test 0.1.3", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
	//otherwise return to the application 
	else
	{
		e->Cancel = true;
	}
}


private: System::Void dataHistoryTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if (e->KeyChar == ';' ||  e->KeyChar == ',')
	{
		MessageBox::Show("Try to avoid  " + e->KeyChar + "  character","Type error");
		e->KeyChar = (char)0;
	}
}
};
}

