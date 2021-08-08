
// ImageClassificationDlg.h: 헤더 파일
//

#pragma once
#define WM_USER_MESSAGE1 (WM_USER + 1) // 사용자 메세지 정의 

#include <opencv2/opencv.hpp>
#include <torch/script.h>
#include <torch/torch.h>
#include <string>

// CImageClassificationDlg 대화 상자
class CImageClassificationDlg : public CDialogEx
{
// 생성입니다.
public:
	CImageClassificationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CString m_image_path;  // 이미지 경로 
	CImage m_image;        // CImage
	CRect m_image_rect;    // 이미지 크기 저장할 CRect 
	std::vector<std::string> labels; // 이미지넷 레이블 
	torch::jit::script::Module Model; // torch scrip module 
	cv::Mat m_inference_img; // inference image 

	// 이상하게 클래스 변수 추가가 안된다.. 직접 생성하자 
	CEdit* m_edit_class;
	CEdit* m_edit_probability;
	 
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGECLASSIFICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnImageClassification(WPARAM wParam, LPARAM lParam); // 사용자 메세지 핸들러 생성 
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonImageload();
	CStatic m_picture_box;
};
