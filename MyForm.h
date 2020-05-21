#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>


cv::VideoCapture cam(0);
double dWidth = cam.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH);
double dHeight = cam.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT);
cv::Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
std::string path = "C:\\Users\\cruel\\Desktop\\";

cv::Mat pic;
cv::Mat edit_pic;
int width_ = edit_pic.cols;
int height_ = edit_pic.rows;

std::string filename_input;
std::string lastImageFilename;
std::string lastVideoFilename;
int shapeType = 0;
int morphType = 0;
int imageCount = 0;
int videoCount = 0;
double scale_coefficient = 1;

char codecs[9][4] =
{
	'X', 'V', 'I', 'D',
	'P', 'I', 'M', '1',
	'M', 'P', '4', '2',
	'D', 'I', 'V', '3',
	'D', 'I', 'V', 'X',
	'U', '2', '6', '3',
	'I', '2', '6', '3',
	'F', 'L', 'V', '1'
};

cv::Mat takePicture()
{
	while(!cam.isOpened())
	{
		std::cout << "Failed to make connection to cam" << std::endl;
		cam.open(0);
	}
	cam >> pic;
	return pic;
}

namespace MediaPlayer3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			codec_i->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

	  System::Windows::Forms::GroupBox^ picConfig_gb;

	  System::Windows::Forms::Label^ picName_l;
	  System::Windows::Forms::TextBox^ picName_i;
	  System::Windows::Forms::CheckBox^ denoising;
	  System::Windows::Forms::Button^ makePic_b;
	  System::Windows::Forms::Button^ watchLastPic_b;

	  System::Windows::Forms::GroupBox^ vidConfig_gb;

	  System::Windows::Forms::Label^ vidName_l;
	  System::Windows::Forms::TextBox^ vidName_i;
	  System::Windows::Forms::Label^ codec_l;
	  System::Windows::Forms::ComboBox^ codec_i;
	  System::Windows::Forms::Label^ fps_l;
	  System::Windows::Forms::MaskedTextBox^ fps_i;
	  System::Windows::Forms::Button^ makeVid_b;
	  System::Windows::Forms::Button^ watchLastVid_b;

	  System::Windows::Forms::GroupBox^ workPic_gb;

	  System::Windows::Forms::Label^ inPicDir_l;
	  System::Windows::Forms::TextBox^ inPicDir_i;
	  System::Windows::Forms::Button^ inPicDir_b;
	  System::Windows::Forms::Label^ outPicDir_l;
	  System::Windows::Forms::TextBox^ outPicDir_i;
	  System::Windows::Forms::Button^ outPicDir_b;
	  System::Windows::Forms::Label^ picName2_l;
	  System::Windows::Forms::TextBox^ picName2_i;

	  System::Windows::Forms::CheckBox^ recize;
	  System::Windows::Forms::CheckBox^ saveProportion;
	  System::Windows::Forms::Label^ width_l;
	  System::Windows::Forms::MaskedTextBox^ width_i;
	  System::Windows::Forms::Label^ height_l;
	  System::Windows::Forms::MaskedTextBox^ height_i;

	  System::Windows::Forms::GroupBox^ filter2d_gb;

	  System::Windows::Forms::CheckBox^ denoising2;
	  System::Windows::Forms::CheckBox^ inverse;
	  System::Windows::Forms::Label^ smooth_l;
	  System::Windows::Forms::TrackBar^ smooth_tb;
	  System::Windows::Forms::TextBox^ smooth_i;
	  System::Windows::Forms::Label^ brightness_l;
	  System::Windows::Forms::TrackBar^ brightness_tb;
	  System::Windows::Forms::TextBox^ brightness_i;
	  System::Windows::Forms::Label^ contrast_l;
	  System::Windows::Forms::TrackBar^ contrast_tb;
	  System::Windows::Forms::TextBox^ contrast_i;

	  System::Windows::Forms::GroupBox^ morph_gb;

	  System::Windows::Forms::GroupBox^ shape_gb;

	  System::Windows::Forms::RadioButton^ rect;
	  System::Windows::Forms::RadioButton^ cross;
	  System::Windows::Forms::RadioButton^ ellipse;

	  System::Windows::Forms::GroupBox^ effect_gb;

	  System::Windows::Forms::RadioButton^ erode;
	  System::Windows::Forms::RadioButton^ dilate;
	  System::Windows::Forms::RadioButton^ opening;
	  System::Windows::Forms::RadioButton^ closing;
	  System::Windows::Forms::RadioButton^ gradient;
	  System::Windows::Forms::RadioButton^ topHat;
	  System::Windows::Forms::RadioButton^ blackHat;
	  System::Windows::Forms::Label^ kernelSize_l;
	  System::Windows::Forms::TrackBar^ kernelSize_tb;
	  System::Windows::Forms::TextBox^ kernelSize_i;

	  System::Windows::Forms::GroupBox^ edgeDetector_gb;

	  System::Windows::Forms::CheckBox^ sobel;
	  System::Windows::Forms::Label^ sobelKernelSize_l;
	  System::Windows::Forms::MaskedTextBox^ sobelKernelSize_i;
	  System::Windows::Forms::Label^ scale_l;
	  System::Windows::Forms::MaskedTextBox^ scale_i;
	  System::Windows::Forms::Label^ delta_l;
	  System::Windows::Forms::MaskedTextBox^ delta_i;

	  System::Windows::Forms::GroupBox^ watchVid_gb;

	  System::Windows::Forms::Label^ vidName2_l;
	  System::Windows::Forms::TextBox^ vidName2_i;
	  System::Windows::Forms::Button^ vidName2_b;
	  System::Windows::Forms::Button^ watchVid_b;

	  System::Windows::Forms::Button^ watchPic_b;
	  System::Windows::Forms::Button^ change_b;
	  System::Windows::Forms::Button^ save_b;

	  System::Windows::Forms::OpenFileDialog^ ofd;
	  System::Windows::Forms::OpenFileDialog^ ofd2;
	  System::Windows::Forms::FolderBrowserDialog^ fbd;

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
	  System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picConfig_gb = (gcnew System::Windows::Forms::GroupBox());
			this->denoising = (gcnew System::Windows::Forms::CheckBox());
			this->picName_l = (gcnew System::Windows::Forms::Label());
			this->picName_i = (gcnew System::Windows::Forms::TextBox());
			this->makePic_b = (gcnew System::Windows::Forms::Button());
			this->watchLastPic_b = (gcnew System::Windows::Forms::Button());
			this->vidConfig_gb = (gcnew System::Windows::Forms::GroupBox());
			this->fps_l = (gcnew System::Windows::Forms::Label());
			this->codec_l = (gcnew System::Windows::Forms::Label());
			this->watchLastVid_b = (gcnew System::Windows::Forms::Button());
			this->fps_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->codec_i = (gcnew System::Windows::Forms::ComboBox());
			this->vidName_l = (gcnew System::Windows::Forms::Label());
			this->vidName_i = (gcnew System::Windows::Forms::TextBox());
			this->makeVid_b = (gcnew System::Windows::Forms::Button());
			this->workPic_gb = (gcnew System::Windows::Forms::GroupBox());
			this->saveProportion = (gcnew System::Windows::Forms::CheckBox());
			this->morph_gb = (gcnew System::Windows::Forms::GroupBox());
			this->kernelSize_i = (gcnew System::Windows::Forms::TextBox());
			this->kernelSize_l = (gcnew System::Windows::Forms::Label());
			this->effect_gb = (gcnew System::Windows::Forms::GroupBox());
			this->erode = (gcnew System::Windows::Forms::RadioButton());
			this->dilate = (gcnew System::Windows::Forms::RadioButton());
			this->blackHat = (gcnew System::Windows::Forms::RadioButton());
			this->opening = (gcnew System::Windows::Forms::RadioButton());
			this->topHat = (gcnew System::Windows::Forms::RadioButton());
			this->closing = (gcnew System::Windows::Forms::RadioButton());
			this->gradient = (gcnew System::Windows::Forms::RadioButton());
			this->shape_gb = (gcnew System::Windows::Forms::GroupBox());
			this->rect = (gcnew System::Windows::Forms::RadioButton());
			this->cross = (gcnew System::Windows::Forms::RadioButton());
			this->ellipse = (gcnew System::Windows::Forms::RadioButton());
			this->kernelSize_tb = (gcnew System::Windows::Forms::TrackBar());
			this->filter2d_gb = (gcnew System::Windows::Forms::GroupBox());
			this->inverse = (gcnew System::Windows::Forms::CheckBox());
			this->contrast_i = (gcnew System::Windows::Forms::TextBox());
			this->brightness_i = (gcnew System::Windows::Forms::TextBox());
			this->contrast_tb = (gcnew System::Windows::Forms::TrackBar());
			this->contrast_l = (gcnew System::Windows::Forms::Label());
			this->brightness_tb = (gcnew System::Windows::Forms::TrackBar());
			this->brightness_l = (gcnew System::Windows::Forms::Label());
			this->smooth_l = (gcnew System::Windows::Forms::Label());
			this->denoising2 = (gcnew System::Windows::Forms::CheckBox());
			this->smooth_i = (gcnew System::Windows::Forms::TextBox());
			this->smooth_tb = (gcnew System::Windows::Forms::TrackBar());
			this->height_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->width_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->height_l = (gcnew System::Windows::Forms::Label());
			this->width_l = (gcnew System::Windows::Forms::Label());
			this->recize = (gcnew System::Windows::Forms::CheckBox());
			this->picName2_l = (gcnew System::Windows::Forms::Label());
			this->picName2_i = (gcnew System::Windows::Forms::TextBox());
			this->outPicDir_b = (gcnew System::Windows::Forms::Button());
			this->edgeDetector_gb = (gcnew System::Windows::Forms::GroupBox());
			this->delta_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->scale_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->sobelKernelSize_i = (gcnew System::Windows::Forms::MaskedTextBox());
			this->delta_l = (gcnew System::Windows::Forms::Label());
			this->sobel = (gcnew System::Windows::Forms::CheckBox());
			this->scale_l = (gcnew System::Windows::Forms::Label());
			this->sobelKernelSize_l = (gcnew System::Windows::Forms::Label());
			this->inPicDir_b = (gcnew System::Windows::Forms::Button());
			this->outPicDir_i = (gcnew System::Windows::Forms::TextBox());
			this->inPicDir_i = (gcnew System::Windows::Forms::TextBox());
			this->outPicDir_l = (gcnew System::Windows::Forms::Label());
			this->inPicDir_l = (gcnew System::Windows::Forms::Label());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fbd = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->watchPic_b = (gcnew System::Windows::Forms::Button());
			this->change_b = (gcnew System::Windows::Forms::Button());
			this->save_b = (gcnew System::Windows::Forms::Button());
			this->watchVid_gb = (gcnew System::Windows::Forms::GroupBox());
			this->vidName2_b = (gcnew System::Windows::Forms::Button());
			this->vidName2_i = (gcnew System::Windows::Forms::TextBox());
			this->vidName2_l = (gcnew System::Windows::Forms::Label());
			this->watchVid_b = (gcnew System::Windows::Forms::Button());
			this->ofd2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->picConfig_gb->SuspendLayout();
			this->vidConfig_gb->SuspendLayout();
			this->workPic_gb->SuspendLayout();
			this->morph_gb->SuspendLayout();
			this->effect_gb->SuspendLayout();
			this->shape_gb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kernelSize_tb))->BeginInit();
			this->filter2d_gb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrast_tb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightness_tb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smooth_tb))->BeginInit();
			this->edgeDetector_gb->SuspendLayout();
			this->watchVid_gb->SuspendLayout();
			this->SuspendLayout();
			// 
			// picConfig_gb
			// 
			this->picConfig_gb->Controls->Add(this->denoising);
			this->picConfig_gb->Controls->Add(this->picName_l);
			this->picConfig_gb->Controls->Add(this->picName_i);
			this->picConfig_gb->Controls->Add(this->makePic_b);
			this->picConfig_gb->Controls->Add(this->watchLastPic_b);
			this->picConfig_gb->Location = System::Drawing::Point(8, 9);
			this->picConfig_gb->Name = L"picConfig_gb";
			this->picConfig_gb->Size = System::Drawing::Size(243, 199);
			this->picConfig_gb->TabIndex = 0;
			this->picConfig_gb->TabStop = false;
			this->picConfig_gb->Text = L"Photo Configuration";
			// 
			// denoising
			// 
			this->denoising->AutoSize = true;
			this->denoising->Location = System::Drawing::Point(26, 75);
			this->denoising->Name = L"denoising";
			this->denoising->Size = System::Drawing::Size(73, 17);
			this->denoising->TabIndex = 5;
			this->denoising->Text = L"Denoising";
			this->denoising->UseVisualStyleBackColor = true;
			// 
			// picName_l
			// 
			this->picName_l->AutoSize = true;
			this->picName_l->Location = System::Drawing::Point(22, 25);
			this->picName_l->Name = L"picName_l";
			this->picName_l->Size = System::Drawing::Size(112, 13);
			this->picName_l->TabIndex = 2;
			this->picName_l->Text = L"Enter the photo name:";
			// 
			// picName_i
			// 
			this->picName_i->Location = System::Drawing::Point(25, 41);
			this->picName_i->Name = L"picName_i";
			this->picName_i->Size = System::Drawing::Size(197, 20);
			this->picName_i->TabIndex = 1;
			// 
			// makePic_b
			// 
			this->makePic_b->Location = System::Drawing::Point(25, 101);
			this->makePic_b->Name = L"makePic_b";
			this->makePic_b->Size = System::Drawing::Size(197, 37);
			this->makePic_b->TabIndex = 0;
			this->makePic_b->Text = L"Make photo";
			this->makePic_b->UseVisualStyleBackColor = true;
			this->makePic_b->Click += gcnew System::EventHandler(this, &MyForm::makePic_b_Click);
			// 
			// watchLastPic_b
			// 
			this->watchLastPic_b->Location = System::Drawing::Point(26, 144);
			this->watchLastPic_b->Name = L"watchLastPic_b";
			this->watchLastPic_b->Size = System::Drawing::Size(197, 37);
			this->watchLastPic_b->TabIndex = 0;
			this->watchLastPic_b->Text = L"Watch the latest photo";
			this->watchLastPic_b->UseVisualStyleBackColor = true;
			this->watchLastPic_b->Click += gcnew System::EventHandler(this, &MyForm::watchLastPic_b_Click);
			// 
			// vidConfig_gb
			// 
			this->vidConfig_gb->Controls->Add(this->fps_l);
			this->vidConfig_gb->Controls->Add(this->codec_l);
			this->vidConfig_gb->Controls->Add(this->watchLastVid_b);
			this->vidConfig_gb->Controls->Add(this->fps_i);
			this->vidConfig_gb->Controls->Add(this->codec_i);
			this->vidConfig_gb->Controls->Add(this->vidName_l);
			this->vidConfig_gb->Controls->Add(this->vidName_i);
			this->vidConfig_gb->Controls->Add(this->makeVid_b);
			this->vidConfig_gb->Location = System::Drawing::Point(8, 212);
			this->vidConfig_gb->Name = L"vidConfig_gb";
			this->vidConfig_gb->Size = System::Drawing::Size(243, 228);
			this->vidConfig_gb->TabIndex = 0;
			this->vidConfig_gb->TabStop = false;
			this->vidConfig_gb->Text = L"Video Configuration";
			// 
			// fps_l
			// 
			this->fps_l->AutoSize = true;
			this->fps_l->Location = System::Drawing::Point(23, 113);
			this->fps_l->Name = L"fps_l";
			this->fps_l->Size = System::Drawing::Size(76, 13);
			this->fps_l->TabIndex = 4;
			this->fps_l->Text = L"Enter the FPS:";
			// 
			// codec_l
			// 
			this->codec_l->AutoSize = true;
			this->codec_l->Location = System::Drawing::Point(23, 81);
			this->codec_l->Name = L"codec_l";
			this->codec_l->Size = System::Drawing::Size(97, 13);
			this->codec_l->TabIndex = 4;
			this->codec_l->Text = L"Choose the codec:";
			// 
			// watchLastVid_b
			// 
			this->watchLastVid_b->Location = System::Drawing::Point(25, 181);
			this->watchLastVid_b->Name = L"watchLastVid_b";
			this->watchLastVid_b->Size = System::Drawing::Size(197, 37);
			this->watchLastVid_b->TabIndex = 0;
			this->watchLastVid_b->Text = L"Watch the latest video";
			this->watchLastVid_b->UseVisualStyleBackColor = true;
			this->watchLastVid_b->Click += gcnew System::EventHandler(this, &MyForm::watchLastVid_b_Click);
			// 
			// fps_i
			// 
			this->fps_i->BeepOnError = true;
			this->fps_i->Location = System::Drawing::Point(125, 106);
			this->fps_i->Mask = L"00";
			this->fps_i->Name = L"fps_i";
			this->fps_i->Size = System::Drawing::Size(97, 20);
			this->fps_i->TabIndex = 5;
			this->fps_i->Text = L"30";
			// 
			// codec_i
			// 
			this->codec_i->FormattingEnabled = true;
			this->codec_i->Items->AddRange(gcnew cli::array< System::Object^  >(8)
			{
				L"XviD", L"MPEG-1", L"motion-jpeg", L"MPEG-4.2",
					L"MPEG-4", L"H.263", L"H.263.I", L"FLV1"
			});
			this->codec_i->Location = System::Drawing::Point(125, 78);
			this->codec_i->Name = L"codec_i";
			this->codec_i->Size = System::Drawing::Size(97, 21);
			this->codec_i->TabIndex = 3;
			// 
			// vidName_l
			// 
			this->vidName_l->AutoSize = true;
			this->vidName_l->Location = System::Drawing::Point(22, 25);
			this->vidName_l->Name = L"vidName_l";
			this->vidName_l->Size = System::Drawing::Size(111, 13);
			this->vidName_l->TabIndex = 2;
			this->vidName_l->Text = L"Enter the video name:";
			// 
			// vidName_i
			// 
			this->vidName_i->Location = System::Drawing::Point(25, 41);
			this->vidName_i->Name = L"vidName_i";
			this->vidName_i->Size = System::Drawing::Size(197, 20);
			this->vidName_i->TabIndex = 1;
			// 
			// makeVid_b
			// 
			this->makeVid_b->Location = System::Drawing::Point(25, 136);
			this->makeVid_b->Name = L"makeVid_b";
			this->makeVid_b->Size = System::Drawing::Size(197, 37);
			this->makeVid_b->TabIndex = 0;
			this->makeVid_b->Text = L"Make video";
			this->makeVid_b->UseVisualStyleBackColor = true;
			this->makeVid_b->Click += gcnew System::EventHandler(this, &MyForm::makeVid_b_Click);
			// 
			// workPic_gb
			// 
			this->workPic_gb->Controls->Add(this->saveProportion);
			this->workPic_gb->Controls->Add(this->morph_gb);
			this->workPic_gb->Controls->Add(this->filter2d_gb);
			this->workPic_gb->Controls->Add(this->height_i);
			this->workPic_gb->Controls->Add(this->width_i);
			this->workPic_gb->Controls->Add(this->height_l);
			this->workPic_gb->Controls->Add(this->width_l);
			this->workPic_gb->Controls->Add(this->recize);
			this->workPic_gb->Controls->Add(this->picName2_l);
			this->workPic_gb->Controls->Add(this->picName2_i);
			this->workPic_gb->Controls->Add(this->outPicDir_b);
			this->workPic_gb->Controls->Add(this->edgeDetector_gb);
			this->workPic_gb->Controls->Add(this->inPicDir_b);
			this->workPic_gb->Controls->Add(this->outPicDir_i);
			this->workPic_gb->Controls->Add(this->inPicDir_i);
			this->workPic_gb->Controls->Add(this->outPicDir_l);
			this->workPic_gb->Controls->Add(this->inPicDir_l);
			this->workPic_gb->Location = System::Drawing::Point(269, 12);
			this->workPic_gb->Name = L"workPic_gb";
			this->workPic_gb->Size = System::Drawing::Size(511, 428);
			this->workPic_gb->TabIndex = 0;
			this->workPic_gb->TabStop = false;
			this->workPic_gb->Text = L"Work with Image";
			// 
			// saveProportion
			// 
			this->saveProportion->AutoSize = true;
			this->saveProportion->Location = System::Drawing::Point(377, 22);
			this->saveProportion->Name = L"saveProportion";
			this->saveProportion->Size = System::Drawing::Size(101, 17);
			this->saveProportion->TabIndex = 12;
			this->saveProportion->Text = L"Save proportion";
			this->saveProportion->UseVisualStyleBackColor = true;
			this->saveProportion->Visible = false;
			this->saveProportion->CheckedChanged += gcnew System::EventHandler(this, &MyForm::saveProportion_CheckedChanged);
			// 
			// morph_gb
			// 
			this->morph_gb->Controls->Add(this->kernelSize_i);
			this->morph_gb->Controls->Add(this->kernelSize_l);
			this->morph_gb->Controls->Add(this->effect_gb);
			this->morph_gb->Controls->Add(this->shape_gb);
			this->morph_gb->Controls->Add(this->kernelSize_tb);
			this->morph_gb->Location = System::Drawing::Point(256, 79);
			this->morph_gb->Name = L"morph_gb";
			this->morph_gb->Size = System::Drawing::Size(245, 220);
			this->morph_gb->TabIndex = 11;
			this->morph_gb->TabStop = false;
			this->morph_gb->Text = L"Morphology";
			// 
			// kernelSize_i
			// 
			this->kernelSize_i->Location = System::Drawing::Point(181, 189);
			this->kernelSize_i->Name = L"kernelSize_i";
			this->kernelSize_i->ReadOnly = true;
			this->kernelSize_i->Size = System::Drawing::Size(52, 20);
			this->kernelSize_i->TabIndex = 14;
			this->kernelSize_i->Text = L"1";
			// 
			// kernelSize_l
			// 
			this->kernelSize_l->AutoSize = true;
			this->kernelSize_l->Location = System::Drawing::Point(9, 170);
			this->kernelSize_l->Name = L"kernelSize_l";
			this->kernelSize_l->Size = System::Drawing::Size(58, 13);
			this->kernelSize_l->TabIndex = 8;
			this->kernelSize_l->Text = L"Kernel size";
			// 
			// effect_gb
			// 
			this->effect_gb->Controls->Add(this->erode);
			this->effect_gb->Controls->Add(this->dilate);
			this->effect_gb->Controls->Add(this->blackHat);
			this->effect_gb->Controls->Add(this->opening);
			this->effect_gb->Controls->Add(this->topHat);
			this->effect_gb->Controls->Add(this->closing);
			this->effect_gb->Controls->Add(this->gradient);
			this->effect_gb->Location = System::Drawing::Point(115, 20);
			this->effect_gb->Name = L"effect_gb";
			this->effect_gb->Size = System::Drawing::Size(124, 163);
			this->effect_gb->TabIndex = 7;
			this->effect_gb->TabStop = false;
			this->effect_gb->Text = L"Effect";
			// 
			// erode
			// 
			this->erode->AutoSize = true;
			this->erode->Location = System::Drawing::Point(13, 21);
			this->erode->Name = L"erode";
			this->erode->Size = System::Drawing::Size(53, 17);
			this->erode->TabIndex = 7;
			this->erode->TabStop = true;
			this->erode->Text = L"Erode";
			this->erode->UseVisualStyleBackColor = true;
			this->erode->CheckedChanged += gcnew System::EventHandler(this, &MyForm::erode_CheckedChanged);
			// 
			// dilate
			// 
			this->dilate->AutoSize = true;
			this->dilate->Location = System::Drawing::Point(13, 42);
			this->dilate->Name = L"dilate";
			this->dilate->Size = System::Drawing::Size(52, 17);
			this->dilate->TabIndex = 6;
			this->dilate->TabStop = true;
			this->dilate->Text = L"Dilate";
			this->dilate->UseVisualStyleBackColor = true;
			this->dilate->CheckedChanged += gcnew System::EventHandler(this, &MyForm::dilate_CheckedChanged);
			// 
			// blackHat
			// 
			this->blackHat->AutoSize = true;
			this->blackHat->Location = System::Drawing::Point(14, 138);
			this->blackHat->Name = L"blackHat";
			this->blackHat->Size = System::Drawing::Size(70, 17);
			this->blackHat->TabIndex = 5;
			this->blackHat->TabStop = true;
			this->blackHat->Text = L"Black hat";
			this->blackHat->UseVisualStyleBackColor = true;
			this->blackHat->CheckedChanged += gcnew System::EventHandler(this, &MyForm::blackHat_CheckedChanged);
			// 
			// opening
			// 
			this->opening->AutoSize = true;
			this->opening->Location = System::Drawing::Point(13, 61);
			this->opening->Name = L"opening";
			this->opening->Size = System::Drawing::Size(65, 17);
			this->opening->TabIndex = 2;
			this->opening->TabStop = true;
			this->opening->Text = L"Opening";
			this->opening->UseVisualStyleBackColor = true;
			this->opening->CheckedChanged += gcnew System::EventHandler(this, &MyForm::opening_CheckedChanged);
			// 
			// topHat
			// 
			this->topHat->AutoSize = true;
			this->topHat->Location = System::Drawing::Point(14, 120);
			this->topHat->Name = L"topHat";
			this->topHat->Size = System::Drawing::Size(62, 17);
			this->topHat->TabIndex = 4;
			this->topHat->TabStop = true;
			this->topHat->Text = L"Top hat";
			this->topHat->UseVisualStyleBackColor = true;
			this->topHat->CheckedChanged += gcnew System::EventHandler(this, &MyForm::topHat_CheckedChanged);
			// 
			// closing
			// 
			this->closing->AutoSize = true;
			this->closing->Location = System::Drawing::Point(14, 80);
			this->closing->Name = L"closing";
			this->closing->Size = System::Drawing::Size(59, 17);
			this->closing->TabIndex = 1;
			this->closing->TabStop = true;
			this->closing->Text = L"Closing";
			this->closing->UseVisualStyleBackColor = true;
			this->closing->CheckedChanged += gcnew System::EventHandler(this, &MyForm::closing_CheckedChanged);
			// 
			// gradient
			// 
			this->gradient->AutoSize = true;
			this->gradient->Location = System::Drawing::Point(14, 100);
			this->gradient->Name = L"gradient";
			this->gradient->Size = System::Drawing::Size(65, 17);
			this->gradient->TabIndex = 3;
			this->gradient->TabStop = true;
			this->gradient->Text = L"Gradient";
			this->gradient->UseVisualStyleBackColor = true;
			this->gradient->CheckedChanged += gcnew System::EventHandler(this, &MyForm::gradient_CheckedChanged);
			// 
			// shape_gb
			// 
			this->shape_gb->Controls->Add(this->rect);
			this->shape_gb->Controls->Add(this->cross);
			this->shape_gb->Controls->Add(this->ellipse);
			this->shape_gb->Location = System::Drawing::Point(12, 19);
			this->shape_gb->Name = L"shape_gb";
			this->shape_gb->Size = System::Drawing::Size(97, 106);
			this->shape_gb->TabIndex = 6;
			this->shape_gb->TabStop = false;
			this->shape_gb->Text = L"Shape";
			// 
			// rect
			// 
			this->rect->AutoSize = true;
			this->rect->Location = System::Drawing::Point(12, 21);
			this->rect->Name = L"rect";
			this->rect->Size = System::Drawing::Size(48, 17);
			this->rect->TabIndex = 2;
			this->rect->TabStop = true;
			this->rect->Text = L"Rect";
			this->rect->UseVisualStyleBackColor = true;
			this->rect->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rect_CheckedChanged);
			// 
			// cross
			// 
			this->cross->AutoSize = true;
			this->cross->Location = System::Drawing::Point(12, 42);
			this->cross->Name = L"cross";
			this->cross->Size = System::Drawing::Size(51, 17);
			this->cross->TabIndex = 3;
			this->cross->TabStop = true;
			this->cross->Text = L"Cross";
			this->cross->UseVisualStyleBackColor = true;
			this->cross->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cross_CheckedChanged);
			// 
			// ellipse
			// 
			this->ellipse->AutoSize = true;
			this->ellipse->Location = System::Drawing::Point(12, 62);
			this->ellipse->Name = L"ellipse";
			this->ellipse->Size = System::Drawing::Size(55, 17);
			this->ellipse->TabIndex = 4;
			this->ellipse->TabStop = true;
			this->ellipse->Text = L"Ellipse";
			this->ellipse->UseVisualStyleBackColor = true;
			this->ellipse->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ellipse_CheckedChanged);
			// 
			// kernelSize_tb
			// 
			this->kernelSize_tb->LargeChange = 10;
			this->kernelSize_tb->Location = System::Drawing::Point(3, 185);
			this->kernelSize_tb->Maximum = 50;
			this->kernelSize_tb->Name = L"kernelSize_tb";
			this->kernelSize_tb->Size = System::Drawing::Size(173, 45);
			this->kernelSize_tb->SmallChange = 5;
			this->kernelSize_tb->TabIndex = 9;
			this->kernelSize_tb->Scroll += gcnew System::EventHandler(this, &MyForm::kernelSize_tb_Scroll);
			// 
			// filter2d_gb
			// 
			this->filter2d_gb->Controls->Add(this->inverse);
			this->filter2d_gb->Controls->Add(this->contrast_i);
			this->filter2d_gb->Controls->Add(this->brightness_i);
			this->filter2d_gb->Controls->Add(this->contrast_tb);
			this->filter2d_gb->Controls->Add(this->contrast_l);
			this->filter2d_gb->Controls->Add(this->brightness_tb);
			this->filter2d_gb->Controls->Add(this->brightness_l);
			this->filter2d_gb->Controls->Add(this->smooth_l);
			this->filter2d_gb->Controls->Add(this->denoising2);
			this->filter2d_gb->Controls->Add(this->smooth_i);
			this->filter2d_gb->Controls->Add(this->smooth_tb);
			this->filter2d_gb->Location = System::Drawing::Point(14, 152);
			this->filter2d_gb->Name = L"filter2d_gb";
			this->filter2d_gb->Size = System::Drawing::Size(232, 266);
			this->filter2d_gb->TabIndex = 10;
			this->filter2d_gb->TabStop = false;
			this->filter2d_gb->Text = L"2D-filter";
			// 
			// inverse
			// 
			this->inverse->AutoSize = true;
			this->inverse->Location = System::Drawing::Point(115, 19);
			this->inverse->Name = L"inverse";
			this->inverse->Size = System::Drawing::Size(61, 17);
			this->inverse->TabIndex = 19;
			this->inverse->Text = L"Inverse";
			this->inverse->UseVisualStyleBackColor = true;
			// 
			// contrast_i
			// 
			this->contrast_i->Location = System::Drawing::Point(189, 176);
			this->contrast_i->Name = L"contrast_i";
			this->contrast_i->ReadOnly = true;
			this->contrast_i->Size = System::Drawing::Size(37, 20);
			this->contrast_i->TabIndex = 18;
			this->contrast_i->Text = L"0";
			// 
			// brightness_i
			// 
			this->brightness_i->Location = System::Drawing::Point(188, 121);
			this->brightness_i->Name = L"brightness_i";
			this->brightness_i->ReadOnly = true;
			this->brightness_i->Size = System::Drawing::Size(37, 20);
			this->brightness_i->TabIndex = 18;
			this->brightness_i->Text = L"0";
			// 
			// contrast_tb
			// 
			this->contrast_tb->LargeChange = 10;
			this->contrast_tb->Location = System::Drawing::Point(15, 176);
			this->contrast_tb->Maximum = 50;
			this->contrast_tb->Minimum = -50;
			this->contrast_tb->Name = L"contrast_tb";
			this->contrast_tb->Size = System::Drawing::Size(180, 45);
			this->contrast_tb->SmallChange = 5;
			this->contrast_tb->TabIndex = 17;
			this->contrast_tb->Scroll += gcnew System::EventHandler(this, &MyForm::contrast_tb_Scroll);
			// 
			// contrast_l
			// 
			this->contrast_l->AutoSize = true;
			this->contrast_l->Location = System::Drawing::Point(12, 157);
			this->contrast_l->Name = L"contrast_l";
			this->contrast_l->Size = System::Drawing::Size(46, 13);
			this->contrast_l->TabIndex = 16;
			this->contrast_l->Text = L"Contrast";
			// 
			// brightness_tb
			// 
			this->brightness_tb->Location = System::Drawing::Point(15, 117);
			this->brightness_tb->Maximum = 50;
			this->brightness_tb->Minimum = -50;
			this->brightness_tb->Name = L"brightness_tb";
			this->brightness_tb->Size = System::Drawing::Size(180, 45);
			this->brightness_tb->SmallChange = 10;
			this->brightness_tb->TabIndex = 15;
			this->brightness_tb->Scroll += gcnew System::EventHandler(this, &MyForm::brightness_tb_Scroll);
			// 
			// brightness_l
			// 
			this->brightness_l->AutoSize = true;
			this->brightness_l->Location = System::Drawing::Point(12, 101);
			this->brightness_l->Name = L"brightness_l";
			this->brightness_l->Size = System::Drawing::Size(56, 13);
			this->brightness_l->TabIndex = 12;
			this->brightness_l->Text = L"Brightness";
			// 
			// smooth_l
			// 
			this->smooth_l->AutoSize = true;
			this->smooth_l->Location = System::Drawing::Point(12, 43);
			this->smooth_l->Name = L"smooth_l";
			this->smooth_l->Size = System::Drawing::Size(43, 13);
			this->smooth_l->TabIndex = 11;
			this->smooth_l->Text = L"Smooth";
			// 
			// denoising2
			// 
			this->denoising2->AutoSize = true;
			this->denoising2->Location = System::Drawing::Point(13, 19);
			this->denoising2->Name = L"denoising2";
			this->denoising2->Size = System::Drawing::Size(73, 17);
			this->denoising2->TabIndex = 5;
			this->denoising2->Text = L"Denoising";
			this->denoising2->UseVisualStyleBackColor = true;
			// 
			// smooth_i
			// 
			this->smooth_i->Location = System::Drawing::Point(188, 65);
			this->smooth_i->Name = L"smooth_i";
			this->smooth_i->ReadOnly = true;
			this->smooth_i->Size = System::Drawing::Size(38, 20);
			this->smooth_i->TabIndex = 9;
			this->smooth_i->Text = L"1";
			// 
			// smooth_tb
			// 
			this->smooth_tb->LargeChange = 10;
			this->smooth_tb->Location = System::Drawing::Point(13, 65);
			this->smooth_tb->Maximum = 50;
			this->smooth_tb->Minimum = 5;
			this->smooth_tb->Name = L"smooth_tb";
			this->smooth_tb->Size = System::Drawing::Size(182, 45);
			this->smooth_tb->SmallChange = 5;
			this->smooth_tb->TabIndex = 8;
			this->smooth_tb->Value = 5;
			this->smooth_tb->Scroll += gcnew System::EventHandler(this, &MyForm::smooth_tb_Scroll);
			// 
			// height_i
			// 
			this->height_i->BeepOnError = true;
			this->height_i->Location = System::Drawing::Point(424, 51);
			this->height_i->Mask = L"000";
			this->height_i->Name = L"height_i";
			this->height_i->Size = System::Drawing::Size(53, 20);
			this->height_i->TabIndex = 5;
			this->height_i->Visible = false;
			// 
			// width_i
			// 
			this->width_i->BeepOnError = true;
			this->width_i->Location = System::Drawing::Point(318, 51);
			this->width_i->Mask = L"000";
			this->width_i->Name = L"width_i";
			this->width_i->Size = System::Drawing::Size(46, 20);
			this->width_i->TabIndex = 5;
			this->width_i->ValidatingType = System::Int32::typeid;
			this->width_i->Visible = false;
			// 
			// height_l
			// 
			this->height_l->AutoSize = true;
			this->height_l->Location = System::Drawing::Point(381, 54);
			this->height_l->Name = L"height_l";
			this->height_l->Size = System::Drawing::Size(41, 13);
			this->height_l->TabIndex = 7;
			this->height_l->Text = L"Height:";
			this->height_l->Visible = false;
			// 
			// width_l
			// 
			this->width_l->AutoSize = true;
			this->width_l->Location = System::Drawing::Point(275, 54);
			this->width_l->Name = L"width_l";
			this->width_l->Size = System::Drawing::Size(38, 13);
			this->width_l->TabIndex = 6;
			this->width_l->Text = L"Width:";
			this->width_l->Visible = false;
			// 
			// recize
			// 
			this->recize->AutoSize = true;
			this->recize->Location = System::Drawing::Point(278, 22);
			this->recize->Name = L"recize";
			this->recize->Size = System::Drawing::Size(58, 17);
			this->recize->TabIndex = 5;
			this->recize->Text = L"Resize";
			this->recize->UseVisualStyleBackColor = true;
			this->recize->CheckedChanged += gcnew System::EventHandler(this, &MyForm::recize_CheckedChanged);
			// 
			// picName2_l
			// 
			this->picName2_l->AutoSize = true;
			this->picName2_l->Location = System::Drawing::Point(13, 129);
			this->picName2_l->Name = L"picName2_l";
			this->picName2_l->Size = System::Drawing::Size(38, 13);
			this->picName2_l->TabIndex = 5;
			this->picName2_l->Text = L"Name:";
			// 
			// picName2_i
			// 
			this->picName2_i->Location = System::Drawing::Point(59, 126);
			this->picName2_i->Name = L"picName2_i";
			this->picName2_i->Size = System::Drawing::Size(177, 20);
			this->picName2_i->TabIndex = 4;
			// 
			// outPicDir_b
			// 
			this->outPicDir_b->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->outPicDir_b->Location = System::Drawing::Point(208, 82);
			this->outPicDir_b->Name = L"outPicDir_b";
			this->outPicDir_b->Size = System::Drawing::Size(28, 20);
			this->outPicDir_b->TabIndex = 3;
			this->outPicDir_b->Text = L"...";
			this->outPicDir_b->UseVisualStyleBackColor = true;
			this->outPicDir_b->Click += gcnew System::EventHandler(this, &MyForm::outPicDir_b_Click);
			// 
			// edgeDetector_gb
			// 
			this->edgeDetector_gb->Controls->Add(this->delta_i);
			this->edgeDetector_gb->Controls->Add(this->scale_i);
			this->edgeDetector_gb->Controls->Add(this->sobelKernelSize_i);
			this->edgeDetector_gb->Controls->Add(this->delta_l);
			this->edgeDetector_gb->Controls->Add(this->sobel);
			this->edgeDetector_gb->Controls->Add(this->scale_l);
			this->edgeDetector_gb->Controls->Add(this->sobelKernelSize_l);
			this->edgeDetector_gb->Location = System::Drawing::Point(256, 305);
			this->edgeDetector_gb->Name = L"edgeDetector_gb";
			this->edgeDetector_gb->Size = System::Drawing::Size(245, 113);
			this->edgeDetector_gb->TabIndex = 0;
			this->edgeDetector_gb->TabStop = false;
			this->edgeDetector_gb->Text = L"Edge Detector";
			// 
			// delta_i
			// 
			this->delta_i->BeepOnError = true;
			this->delta_i->Location = System::Drawing::Point(98, 85);
			this->delta_i->Mask = L"00";
			this->delta_i->Name = L"delta_i";
			this->delta_i->Size = System::Drawing::Size(53, 20);
			this->delta_i->TabIndex = 5;
			this->delta_i->Visible = false;
			// 
			// scale_i
			// 
			this->scale_i->BeepOnError = true;
			this->scale_i->Location = System::Drawing::Point(98, 64);
			this->scale_i->Mask = L"00";
			this->scale_i->Name = L"scale_i";
			this->scale_i->Size = System::Drawing::Size(53, 20);
			this->scale_i->TabIndex = 5;
			this->scale_i->Visible = false;
			// 
			// sobelKernelSize_i
			// 
			this->sobelKernelSize_i->BeepOnError = true;
			this->sobelKernelSize_i->Location = System::Drawing::Point(98, 43);
			this->sobelKernelSize_i->Mask = L"00";
			this->sobelKernelSize_i->Name = L"sobelKernelSize_i";
			this->sobelKernelSize_i->Size = System::Drawing::Size(53, 20);
			this->sobelKernelSize_i->TabIndex = 5;
			this->sobelKernelSize_i->Visible = false;
			// 
			// delta_l
			// 
			this->delta_l->AutoSize = true;
			this->delta_l->Location = System::Drawing::Point(21, 86);
			this->delta_l->Name = L"delta_l";
			this->delta_l->Size = System::Drawing::Size(32, 13);
			this->delta_l->TabIndex = 7;
			this->delta_l->Text = L"Delta";
			this->delta_l->Visible = false;
			// 
			// sobel
			// 
			this->sobel->AutoSize = true;
			this->sobel->Location = System::Drawing::Point(22, 23);
			this->sobel->Name = L"sobel";
			this->sobel->Size = System::Drawing::Size(53, 17);
			this->sobel->TabIndex = 0;
			this->sobel->Text = L"Sobel";
			this->sobel->UseVisualStyleBackColor = true;
			this->sobel->CheckedChanged += gcnew System::EventHandler(this, &MyForm::sobel_CheckedChanged);
			// 
			// scale_l
			// 
			this->scale_l->AutoSize = true;
			this->scale_l->Location = System::Drawing::Point(21, 67);
			this->scale_l->Name = L"scale_l";
			this->scale_l->Size = System::Drawing::Size(34, 13);
			this->scale_l->TabIndex = 7;
			this->scale_l->Text = L"Scale";
			this->scale_l->Visible = false;
			// 
			// sobelKernelSize_l
			// 
			this->sobelKernelSize_l->AutoSize = true;
			this->sobelKernelSize_l->Location = System::Drawing::Point(21, 46);
			this->sobelKernelSize_l->Name = L"sobelKernelSize_l";
			this->sobelKernelSize_l->Size = System::Drawing::Size(60, 13);
			this->sobelKernelSize_l->TabIndex = 6;
			this->sobelKernelSize_l->Text = L"Kernel Size";
			this->sobelKernelSize_l->Visible = false;
			// 
			// inPicDir_b
			// 
			this->inPicDir_b->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->inPicDir_b->Location = System::Drawing::Point(208, 38);
			this->inPicDir_b->Name = L"inPicDir_b";
			this->inPicDir_b->Size = System::Drawing::Size(28, 20);
			this->inPicDir_b->TabIndex = 3;
			this->inPicDir_b->Text = L"...";
			this->inPicDir_b->UseVisualStyleBackColor = true;
			this->inPicDir_b->Click += gcnew System::EventHandler(this, &MyForm::inPicDir_b_Click);
			// 
			// outPicDir_i
			// 
			this->outPicDir_i->Location = System::Drawing::Point(16, 82);
			this->outPicDir_i->Name = L"outPicDir_i";
			this->outPicDir_i->Size = System::Drawing::Size(186, 20);
			this->outPicDir_i->TabIndex = 1;
			// 
			// inPicDir_i
			// 
			this->inPicDir_i->Location = System::Drawing::Point(16, 38);
			this->inPicDir_i->Name = L"inPicDir_i";
			this->inPicDir_i->Size = System::Drawing::Size(186, 20);
			this->inPicDir_i->TabIndex = 1;
			// 
			// outPicDir_l
			// 
			this->outPicDir_l->AutoSize = true;
			this->outPicDir_l->Location = System::Drawing::Point(13, 66);
			this->outPicDir_l->Name = L"outPicDir_l";
			this->outPicDir_l->Size = System::Drawing::Size(87, 13);
			this->outPicDir_l->TabIndex = 2;
			this->outPicDir_l->Text = L"Output Directory:";
			// 
			// inPicDir_l
			// 
			this->inPicDir_l->AutoSize = true;
			this->inPicDir_l->Location = System::Drawing::Point(13, 22);
			this->inPicDir_l->Name = L"inPicDir_l";
			this->inPicDir_l->Size = System::Drawing::Size(66, 13);
			this->inPicDir_l->TabIndex = 2;
			this->inPicDir_l->Text = L"Input Image:";
			// 
			// watchPic_b
			// 
			this->watchPic_b->Location = System::Drawing::Point(281, 446);
			this->watchPic_b->Name = L"watchPic_b";
			this->watchPic_b->Size = System::Drawing::Size(155, 37);
			this->watchPic_b->TabIndex = 0;
			this->watchPic_b->Text = L"Watch";
			this->watchPic_b->UseVisualStyleBackColor = true;
			this->watchPic_b->Click += gcnew System::EventHandler(this, &MyForm::watchPic_b_Click);
			// 
			// change_b
			// 
			this->change_b->Location = System::Drawing::Point(442, 446);
			this->change_b->Name = L"change_b";
			this->change_b->Size = System::Drawing::Size(155, 37);
			this->change_b->TabIndex = 0;
			this->change_b->Text = L"Change";
			this->change_b->UseVisualStyleBackColor = true;
			this->change_b->Click += gcnew System::EventHandler(this, &MyForm::change_b_Click);
			// 
			// save_b
			// 
			this->save_b->Location = System::Drawing::Point(603, 446);
			this->save_b->Name = L"save_b";
			this->save_b->Size = System::Drawing::Size(155, 37);
			this->save_b->TabIndex = 0;
			this->save_b->Text = L"Save";
			this->save_b->UseVisualStyleBackColor = true;
			this->save_b->Click += gcnew System::EventHandler(this, &MyForm::save_b_Click);
			// 
			// watchVid_gb
			// 
			this->watchVid_gb->Controls->Add(this->vidName2_b);
			this->watchVid_gb->Controls->Add(this->vidName2_i);
			this->watchVid_gb->Controls->Add(this->vidName2_l);
			this->watchVid_gb->Controls->Add(this->watchVid_b);
			this->watchVid_gb->Location = System::Drawing::Point(795, 12);
			this->watchVid_gb->Name = L"watchVid_gb";
			this->watchVid_gb->Size = System::Drawing::Size(252, 119);
			this->watchVid_gb->TabIndex = 1;
			this->watchVid_gb->TabStop = false;
			this->watchVid_gb->Text = L"Watch Video";
			// 
			// vidName2_b
			// 
			this->vidName2_b->Location = System::Drawing::Point(211, 35);
			this->vidName2_b->Name = L"vidName2_b";
			this->vidName2_b->Size = System::Drawing::Size(24, 19);
			this->vidName2_b->TabIndex = 3;
			this->vidName2_b->Text = L"...";
			this->vidName2_b->UseVisualStyleBackColor = true;
			this->vidName2_b->Click += gcnew System::EventHandler(this, &MyForm::vidName2_b_Click);
			// 
			// vidName2_i
			// 
			this->vidName2_i->Location = System::Drawing::Point(15, 35);
			this->vidName2_i->Name = L"vidName2_i";
			this->vidName2_i->Size = System::Drawing::Size(186, 20);
			this->vidName2_i->TabIndex = 1;
			// 
			// vidName2_l
			// 
			this->vidName2_l->AutoSize = true;
			this->vidName2_l->Location = System::Drawing::Point(12, 19);
			this->vidName2_l->Name = L"vidName2_l";
			this->vidName2_l->Size = System::Drawing::Size(64, 13);
			this->vidName2_l->TabIndex = 2;
			this->vidName2_l->Text = L"Input Video:";
			// 
			// watchVid_b
			// 
			this->watchVid_b->Location = System::Drawing::Point(46, 71);
			this->watchVid_b->Name = L"watchVid_b";
			this->watchVid_b->Size = System::Drawing::Size(155, 37);
			this->watchVid_b->TabIndex = 0;
			this->watchVid_b->Text = L"Watch";
			this->watchVid_b->UseVisualStyleBackColor = true;
			this->watchVid_b->Click += gcnew System::EventHandler(this, &MyForm::watchVid_b_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1059, 490);
			this->Controls->Add(this->watchVid_gb);
			this->Controls->Add(this->workPic_gb);
			this->Controls->Add(this->save_b);
			this->Controls->Add(this->change_b);
			this->Controls->Add(this->watchPic_b);
			this->Controls->Add(this->picConfig_gb);
			this->Controls->Add(this->vidConfig_gb);
			this->Name = L"OpenCVCam";
			this->Text = L"OpenCVcam";
			this->picConfig_gb->ResumeLayout(false);
			this->picConfig_gb->PerformLayout();
			this->vidConfig_gb->ResumeLayout(false);
			this->vidConfig_gb->PerformLayout();
			this->workPic_gb->ResumeLayout(false);
			this->workPic_gb->PerformLayout();
			this->morph_gb->ResumeLayout(false);
			this->morph_gb->PerformLayout();
			this->effect_gb->ResumeLayout(false);
			this->effect_gb->PerformLayout();
			this->shape_gb->ResumeLayout(false);
			this->shape_gb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kernelSize_tb))->EndInit();
			this->filter2d_gb->ResumeLayout(false);
			this->filter2d_gb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrast_tb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightness_tb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->smooth_tb))->EndInit();
			this->edgeDetector_gb->ResumeLayout(false);
			this->edgeDetector_gb->PerformLayout();
			this->watchVid_gb->ResumeLayout(false);
			this->watchVid_gb->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private:

	  System::Void inPicDir_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ofd->ShowDialog();
			inPicDir_i->Text = ofd->SafeFileName;
			filename_input = msclr::interop::marshal_as<std::string>(ofd->FileName);
			edit_pic = imread(filename_input, cv::ImreadModes::IMREAD_COLOR);

		}

	  System::Void outPicDir_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			fbd->ShowDialog();
			outPicDir_i->Text = fbd->SelectedPath;
		}

	  System::Void recize_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if(recize->Checked)
			{
				saveProportion->Visible = true;
				width_i->Visible = true;
				height_i->Visible = true;
				width_l->Visible = true;
				height_l->Visible = true;
			}
			else
			{
				saveProportion->Visible = false;
				width_i->Visible = false;
				height_i->Visible = false;
				width_l->Visible = false;
				height_l->Visible = false;
			}
		}

	  System::Void vidName2_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ofd2->ShowDialog();
			vidName2_i->Text = ofd2->SafeFileName;
		}

	  System::Void makePic_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			cv::Mat image = takePicture();
			
			if(denoising->Checked)
			{
				cv::fastNlMeansDenoisingColored(image, image);
			}

			std::string filename = msclr::interop::marshal_as<std::string>(picName_i->Text);
			filename = path + std::to_string(imageCount) + filename + "_im.png";

			cv::imwrite(filename, image);
			cv::imshow("This is you!", image);
			lastImageFilename = filename;
			imageCount++;
		}

	  System::Void watchLastPic_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			cv::Mat image = imread(lastImageFilename, cv::ImreadModes::IMREAD_COLOR);

			if(image.empty())
			{
				std::cout << "Could not read the image";
			}
			imshow("The last taken photo", image);
		}

	  System::Void makeVid_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			std::string filename = msclr::interop::marshal_as<std::string>(vidName_i->Text);
			filename = path + std::to_string(videoCount) + filename + "_vid.avi";
			int i = codec_i->SelectedIndex;
			int fps = std::stoi(msclr::interop::marshal_as<std::string>(fps_i->Text));

			cv::VideoWriter videoWriter(filename, cv::VideoWriter::fourcc(codecs[i][0], codecs[i][1], codecs[i][2], codecs[i][3]), fps, frameSize, true);
			if(!videoWriter.isOpened())
			{
				std::cout << "Can't write video.";
			}

			while(true)
			{
				cv::Mat frame;
				bool bSuccess = cam.read(frame);
				if(!bSuccess)
				{
					std::cout << "Can't read from video file.";
					break;
				}

				videoWriter.write(frame);
				imshow("Press Esc to stop recording video", frame);

				int key = cv::waitKey(50);
				if(key == 27)
				{
					std::cout << "Goodbye\n";
					break;
				}
			}
			cv::destroyAllWindows();
			videoCount++;
			lastVideoFilename = filename;
		}

	  System::Void watchLastVid_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			cv::VideoCapture cap(lastVideoFilename);
			if(!cap.isOpened())
			{
				std::cout << "Cannot open the video file.\n";
			}
			double fps = cap.get(cv::VideoCaptureProperties::CAP_PROP_FPS);
			namedWindow("The last recorded video", cv::WindowFlags::WINDOW_AUTOSIZE);

			while(true)
			{
				cv::Mat frame;

				if(!cap.read(frame))
				{
					std::cout << "\nCannot read the video file\n";
					break;
				}
				cv::imshow("The last recorded video", frame);

				if(cv::waitKey(30) == 27)
				{
					break;
				}
			}
			cv::destroyAllWindows();
		}

	  System::Void watchPic_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			edit_pic = imread(filename_input, cv::ImreadModes::IMREAD_COLOR);
			if(edit_pic.empty())
			{
				std::cout << "Could not read the image";
			}
			imshow("Your photo", edit_pic);
			imageCount++;
		}

	  System::Void watchVid_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			std::string filename = msclr::interop::marshal_as<std::string>(ofd2->FileName);
			cv::VideoCapture cap(filename);

			if(!cap.isOpened())
			{
				std::cout << "Cannot open the video file.\n";
			}
			double fps = cap.get(cv::VideoCaptureProperties::CAP_PROP_FPS);
			namedWindow("Your video", cv::WindowFlags::WINDOW_AUTOSIZE);

			while(true)
			{
				cv::Mat frame;
				if(!cap.read(frame))
				{
					std::cout << "\nCannot read the video file\n";
					break;
				}
				cv::imshow("Your video", frame);

				if(cv::waitKey(30) == 27)
				{
					break;
				}
			}
			cv::destroyAllWindows();
		}

	  System::Void save_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			std::string filename = msclr::interop::marshal_as<std::string>(fbd->SelectedPath);
			std::string name = msclr::interop::marshal_as<std::string>(picName2_i->Text);
			filename = filename + "\\" + std::to_string(imageCount) + name + "_im.png";

			cv::imwrite(filename, edit_pic);
			lastImageFilename = filename;
			imageCount++;
		}

	  System::Void change_b_Click(System::Object^ sender, System::EventArgs^ e)
		{
			edit_pic = imread(filename_input, cv::ImreadModes::IMREAD_COLOR);

			if(denoising2->Checked)
			{
				cv::fastNlMeansDenoisingColored(edit_pic, edit_pic);
			}

			if(inverse->Checked)
			{
				cv::bitwise_not(edit_pic, edit_pic);
			}

			int brightness = std::stoi(msclr::interop::marshal_as<std::string>(brightness_i->Text));
			double contrast = std::stoi(msclr::interop::marshal_as<std::string>(contrast_i->Text));
			contrast += 50;
			contrast /= 50;

			edit_pic.convertTo(edit_pic, -1, contrast, brightness);

			int smooth = std::stoi(msclr::interop::marshal_as<std::string>(smooth_i->Text));
			if(smooth != 0)
			{
				smooth = (smooth % 2 == 0) ? smooth + 1 : smooth;
				cv::GaussianBlur(edit_pic, edit_pic, cv::Size(smooth, smooth), 0);
			}

			if(sobel->Checked)
			{
				int depth = CV_16S;
				int sKernelSize = std::stoi(msclr::interop::marshal_as<std::string>(sobelKernelSize_i->Text));
				sKernelSize = sKernelSize < 30 ? sKernelSize : 30;
				int scale = std::stoi(msclr::interop::marshal_as<std::string>(scale_i->Text));
				int delta = std::stoi(msclr::interop::marshal_as<std::string>(delta_i->Text));

				cv::Mat src;
				cv::Mat src_gray;

				cv::GaussianBlur(edit_pic, src, cv::Size(3, 3), 0, 0, cv::BorderTypes::BORDER_DEFAULT);
				cv::cvtColor(src, src_gray, cv::ColorConversionCodes::COLOR_BGR2GRAY);

				cv::Mat grad_x, grad_y;
				cv::Mat abs_grad_x, abs_grad_y;

				cv::Sobel(src_gray, grad_x, depth, 1, 0, sKernelSize, scale, delta, cv::BorderTypes::BORDER_DEFAULT);
				cv::Sobel(src_gray, grad_y, depth, 0, 1, sKernelSize, scale, delta, cv::BorderTypes::BORDER_DEFAULT);
				cv::convertScaleAbs(grad_x, abs_grad_x);
				cv::convertScaleAbs(grad_y, abs_grad_y);
				cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, edit_pic);
			}

			int kernelSize = std::stoi(msclr::interop::marshal_as<std::string>(kernelSize_i->Text));
			cv::Mat element = cv::getStructuringElement(shapeType, cv::Size(2 * kernelSize + 1, 2 * kernelSize + 1), cv::Point(kernelSize, kernelSize));
			cv::morphologyEx(edit_pic, edit_pic, morphType, element);

			if(recize->Checked)
			{
				if(saveProportion->Checked)
				{
					int width = std::stoi(msclr::interop::marshal_as<std::string>(width_i->Text));
					scale_coefficient = static_cast<double>(width) / edit_pic.size().width;
					std::string height = std::to_string(edit_pic.size().height * scale_coefficient);
					height_i->Text = msclr::interop::marshal_as<String^>(height);
				}
				double scaleWidth = scale_coefficient;
				double scaleHeight = scale_coefficient;

				if(!saveProportion->Checked)
				{
					int width = std::stoi(msclr::interop::marshal_as<std::string>(width_i->Text));
					scaleWidth = width / edit_pic.size().width;
					int height = std::stoi(msclr::interop::marshal_as<std::string>(height_i->Text));
					scaleHeight = height / edit_pic.size().height;
				}
				cv::resize(edit_pic, edit_pic, cv::Size(0, 0), scaleWidth, scaleHeight);
			}
			imshow("Edited photo:", edit_pic);
		}

	  System::Void smooth_tb_Scroll(System::Object^ sender, System::EventArgs^ e)
		{
			smooth_i->Text = smooth_tb->Value.ToString();
		}

	  System::Void kernelSize_tb_Scroll(System::Object^ sender, System::EventArgs^ e)
		{
			kernelSize_i->Text = kernelSize_tb->Value.ToString();
		}

	  System::Void brightness_tb_Scroll(System::Object^ sender, System::EventArgs^ e)
		{
			brightness_i->Text = brightness_tb->Value.ToString();
		}

	  System::Void contrast_tb_Scroll(System::Object^ sender, System::EventArgs^ e)
		{
			contrast_i->Text = contrast_tb->Value.ToString();
		}

	  System::Void rect_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			shapeType = 0;
		}

	  System::Void cross_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			shapeType = 1;
		}

	  System::Void ellipse_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			shapeType = 2;
		}

	  System::Void opening_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 2;
		}

	  System::Void closing_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 3;
		}

	  System::Void gradient_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 4;
		}

	  System::Void topHat_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 5;
		}

	  System::Void blackHat_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 6;
		}

	  System::Void erode_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 0;
		}

	  System::Void dilate_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			morphType = 1;
		}

	  System::Void saveProportion_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{}

	  System::Void sobel_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if(sobel->Checked)
			{
				sobelKernelSize_i->Visible = true;
				sobelKernelSize_l->Visible = true;
				delta_i->Visible = true;
				delta_l->Visible = true;
				scale_i->Visible = true;
				scale_l->Visible = true;
			}
			else
			{
				sobelKernelSize_i->Visible = false;
				sobelKernelSize_l->Visible = false;
				delta_i->Visible = false;
				delta_l->Visible = false;
				scale_i->Visible = false;
				scale_l->Visible = false;
			}
		}
  };
}
