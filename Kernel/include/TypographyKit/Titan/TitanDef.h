//===========================================================================
// Summary:
//		�����ṹ����
// Usage:
//		Null
// Remarks:
//		Null
// Date:
//		2011-08-18
// Author:
//		Wang Yi (wangyi@duokan.com)
//===========================================================================

#ifndef	__TITANDEF_HEADERFILE__
#define __TITANDEF_HEADERFILE__

//===========================================================================

#include <math.h>
#include <string>
#include <vector>
using namespace std;

//===========================================================================

#define TITANEXPORT
#define TITANSTDMETHODCALLTYPE		__stdcall
#define TITANAPI					extern "C" TITANEXPORT bool
#define TITANAPI_(type)				extern "C" TITANEXPORT type

//===========================================================================

#undef TITAN_NATIVE_WIDE_CHAR_SUPPORT
#ifdef _ANDROID_LINUX
#define TITAN_NATIVE_WIDE_CHAR_SUPPORT
#endif

//===========================================================================

#ifdef TITAN_NATIVE_WIDE_CHAR_SUPPORT
typedef int TP_WCHAR;
typedef std::basic_string<TP_WCHAR, std::char_traits<TP_WCHAR>, std::allocator<TP_WCHAR> > TP_WSTRING;
#else
typedef wchar_t TP_WCHAR;
typedef std::wstring TP_WSTRING;
#endif

//===========================================================================

typedef void*	TP_HANDLE;

//===========================================================================

// �Ű��״̬
enum TP_LAYOUT_STATE
{
	TP_LAYOUT_SUCCEED		= 0x01,			// ���ж����Ű�ɹ�
	TP_LAYOUT_FOLLOWAFTER	= 0x02,			// �Ű沿�ֳɹ�����Ҫ���������Ű�
	TP_LAYOUT_FAIL			= 0X03,			// �Ű�ʧ��
	TP_LAYOUT_INIT_FAIL		= 0x04,			// ��ʼ��ʧ��
	TP_LAYOUT_OUTOFROOM		= 0x05,			// �ռ䲻��
	TP_LAYOUT_INPUT_NO_TEXT = 0x06			// û�д������֣����Ŵ�����Ϊ0��
};

// ������뼯
enum TP_CHARSET_TYPE
{
	TP_CHARSET_ANSI,
	TP_CHARSET_PRC,
	TP_CHARSET_BIG5	
};

// ���뷽ʽ
enum TP_ALIGN_TYPE
{
	TP_ALIGN_LEFT,
	TP_ALIGN_RIGHT,
	TP_ALIGN_CENTER,
	TP_ALIGN_JUSTIFY
};

// ������λ
enum TP_MEASURE_TYPE
{
	TP_MEASURE_PIXEL,						// ���ص�
	TP_MEASURE_POINT,						// ��������Ϊ1/72Ӣ��
	TP_MEASURE_CM,							// ����
	TP_MEASURE_MM,							// ����
	TP_MEASURE_INCH,						// Ӣ��
	TP_MEASURE_CUSTOM						// �û��Զ���
};

// Piece����
enum TP_PIECE_TYPE
{
	TP_PIECE_TEXT,							// ���ֿ�
	TP_PIECE_NEWLINE,						// ǿ�ƻ��п�
	TP_PIECE_NEWPARA,						// ���ο飬Ŀǰֻ����HTML������
    TP_PIECE_PARAEND,                       // �ν���
	TP_PIECE_GRAPH,							// ͼ�ο�
	TP_PIECE_IMAGE,							// ͼ���
	TP_PIECE_FIGURENOTE,					// ͼע
	TP_PIECE_RUBY,							// ƴע��
	TP_PIECE_HORINVER,						// ���к�
	TP_PIECE_COMBINELINES,					// ��������
};

// ͼ�Ĺ�ϵ
enum TP_WRAPPING_TYPE
{
	TP_WRAPPING_AROUND,						// ���ֻ���
	TP_WRAPPING_ALONE,						// ��ռ
	TP_WRAPPING_FOLLOW						// ����
};

enum TP_FOLLOWIMAGE_TYPE
{
    TP_FOLLOWIMAGE_IMAGE,                   // ����ͼ
    TP_FOLLOWIMAGE_NOTE,                    // ����ע
    TP_FOLLOWIMAGE_CHARACTER                // ����
};

// ���д������
enum TP_BLANKLINE_STRATEGY
{
	TP_BLANKLINE_COPY,						// ������Դ����һ��
	TP_BLANKLINE_SINGLE,					// �����������ѹ��Ϊһ������
	TP_BLANKLINE_IGNOREALL					// �������п���
};

// ���嶨�巽ʽ
enum TP_FONTDEFINE_TYPE
{
	TP_FONTDEFINE_FACENAME,					// ������
	TP_FONTDEFINE_FILENAME,					// �����ļ�·��
	TP_FONTDEFINE_HANDLE					// �Զ�����
};

// �м�ඨ�巽ʽ
enum TP_LINEGAP_TYPE
{
	TP_LINEGAP_MULTIPLE,					// �౶�о�
	TP_LINEGAP_FIXEDVALUE					// ���ù̶�ֵ
};

// ����֧�ֵ��ַ���������Ϊ���ֵ��
enum TP_FONTCHARSET_TYPE
{
	TP_FONTCHARSET_LATIN	= 0x1,			// �����ַ���
	TP_FONTCHARSET_GB		= 0x2,			// �����ַ���
};

// ������
enum TP_FONTSTYLE_TYPE
{
	TP_FONTSTYLE_USERDEFINED,				// �û��Զ����񣬵�ʹ��MP_FONTDEFINE_HANDLEʱ����
	TP_FONTSTYLE_NORMAL,					// ��ͨ
	TP_FONTSTYLE_ITALIC						// ��б
};

// ����Ũ��
enum TP_FONTWEIGHT_TYPE
{
	TP_FONTWEIGHT_USERDEFINED,				// �û��Զ���Ũ������ʹ��MP_FONTDEFINE_HANDLEʱ����
	TP_FONTWEIGHT_NORMAL,					// ��ͨ
	TP_FONTWEIGHT_BOLD						// �Ӵ�
};

// �ı�Ƭ�ε����ͣ�Ŀǰֻ������HTML������
enum TP_TEXTPIECE_TYPE
{
    TP_TEXTPIECE_NORMAL,                    // �������ı��������ñ�׼HTML�հ��ַ�������Ժ���ı�
    TP_TEXTPIECE_PRE                        // pre��ǩ�ڵ��ı���������HTML�ı�ԭ��ʽ���ı�
};

// ����������ʱ�����ʽ
enum TP_PUNCTUATION_VERTICAL_STYLE
{
	TP_PUNCTUATION_VERTICAL_STYLE_CHS = 0,	// ����������ʽ
	TP_PUNCTUATION_VERTICAL_STYLE_CHT,		// ����������ʽ
	TP_PUNCTUATION_VERTICAL_STYLE_JP		// ������ʽ
};

// Hyphenationʹ�õ�����
enum TP_HYPHENATION_LANGUAGE
{
	TP_HYPHENATION_LANGUAGE_UNDEFINED = 0,	// δ���壬����Hyphenation����
	TP_HYPHENATION_LANGUAGE_AUTOMATION,		// �Ű���������ַ��������������Զ�����Hyphen����ѡ�
	TP_HYPHENATION_LANGUAGE_EN,				// Ӣ��
	TP_HYPHENATION_LANGUAGE_DE,				// ����
	TP_HYPHENATION_LANGUAGE_DE_TRADITIONAL	// ��ͳ����	
};

// ƴע�����뷽ʽ
enum TP_RUBY_ALIGN_TYPE
{
	TP_RUBY_ALIGN_CENTER = 0,				// ���������ʾ
	TP_RUBY_ALIGN_LEFT,						// ���������ʾ
	TP_RUBY_ALIGN_RIGHT,					// ���������ʾ
	TP_RUBY_ALIGN_DISTRIBUTE_LETTER,		// �������˶���
	TP_RUBY_ALIGN_DISTRIBUTE_SPACE			// ������β�ַ�����п�λ����λ���Ϊ���������ַ�����һ��
};

// ƴע��λ��
enum TP_RUBY_POSITION
{
	TP_RUBY_POSITION_BEFORE = 0,			// ��������λ����������֮ǰ
	TP_RUBY_POSITION_AFTER					// ��������λ����������֮��
};

// �Ű淽������
enum TP_DIRECTION_TYPE
{
	TP_DIRECTION_LTR_TTB,					// �������ң��������º��š�
	TP_DIRECTION_TTB_RTL					// �������£������������š�
};

// �Ű��ַ���������
enum TP_GRAVITY_DIRECTION
{
	TP_GRAVITY_DOWN = 0,        			// �ַ������������£���ΪĬ��״̬
	TP_GRAVITY_LEFT,						// �ַ�������������
	TP_GRAVITY_UP,							// �ַ�������������
	TP_GRAVITY_RIGHT,						// �ַ�������������
	TP_GRAVITY_AUTO
};

// ���Ӵ�ֱ����Ķ��뷽ʽ
enum TP_BOX_VALIGN_TYPE
{
    TP_BOX_VALIGN_BASELINE = 0, // �����ֻ���
    TP_BOX_VALIGN_TOPLINE,      // �����־����ϱ߽�
    TP_BOX_VALIGN_MIDDLELINE,   // �����־�������
    TP_BOX_VALIGN_BOTTOMLINE    // �����־����±߽�
};

// ���Ӵ�С�ĵ�λ
enum TP_LENGTH_UNIT
{
    TP_LENGTH_UNKNOWN,
    TP_LENGTH_PERCENT,
    TP_LENGTH_PX
};

// CJK�Ű滷�����ã�����Ϊ���ֵ��
enum TP_CJK_LAYOUT_ENV
{
    ENV_AUTO_ADJUST_CJK_LATIN_NUM_DISTANCE  = 0x01, // �Զ��������ĺ����ġ����ֵļ��
    ENV_ALLOW_PUNCTUATION_OVERFLOW          = 0x02, // ����CJK�������߽�
    ENV_SHRINK_CJK_PUNCTUATION              = 0x04, // ѹ��CJK���
    ENV_SHRINK_LINE_BEGIN_PUNCTUATION       = 0x08, // �����������ı��ѹ����ֻ��������SHRINK_CJK_PUNCTUATION������²����������ֵ
    ENV_ALLOW_USE_KERNING                   = 0x10, // ������Kerning
    ENV_ALLOW_USE_HYPHEN                    = 0x20, // ������Hyphen
    ENV_SHRINK_LINE_END_PUNCTUATION         = 0x40, // ǿ����β���ı��ѹ����ֻ��������SHRINK_CJK_PUNCTUATION������²����������ֵ

    ENV_NONE                                = 0x00, 
    ENV_DEFAULT                             = ENV_AUTO_ADJUST_CJK_LATIN_NUM_DISTANCE 
                                            //| ENV_ALLOW_PUNCTUATION_OVERFLOW 
                                            | ENV_SHRINK_CJK_PUNCTUATION 
                                            | ENV_SHRINK_LINE_BEGIN_PUNCTUATION 
                                            | ENV_ALLOW_USE_KERNING 
                                            | ENV_ALLOW_USE_HYPHEN 
                                            //| ENV_SHRINK_LINE_END_PUNCTUATION
};

#define TP_AUTO_ADJUST_CJK_LATIN_NUM_DISTANCE(env)  (0 != ((env) & ENV_AUTO_ADJUST_CJK_LATIN_NUM_DISTANCE))
#define TP_ALLOW_PUNCTUATION_OVERFLOW(env)          (0 != ((env) & ENV_ALLOW_PUNCTUATION_OVERFLOW))
#define TP_SHRINK_CJK_PUNCTUATION(env)              (0 != ((env) & ENV_SHRINK_CJK_PUNCTUATION))
#define TP_SHRINK_LINE_BEGIN_PUNCTUATION(env)       (0 != ((env) & ENV_SHRINK_LINE_BEGIN_PUNCTUATION))
#define TP_ALLOW_USE_KERNING(env)                   (0 != ((env) & ENV_ALLOW_USE_KERNING))
#define TP_ALLOW_USE_HYPHEN(env)                    (0 != ((env) & ENV_ALLOW_USE_HYPHEN))
#define TP_SHRINK_LINE_END_PUNCTUATION(env)         (0 != ((env) & ENV_SHRINK_LINE_END_PUNCTUATION))

//===========================================================================

// �ж������������Ƿ����
#define TP_DELTA		0.0001
#define D_EQUAL(x, y)	(fabs((x) - (y)) <= TP_DELTA)

// �ļ�·���������ֵ
#ifdef MAX_PATH
#define TP_MAX_PATH	MAX_PATH
#else
#define TP_MAX_PATH	260
#endif

// λ��������������
struct TP_POS 
{
	double X;
	double Y;

	TP_POS()
		: X(0.0), Y(0.0)
	{}

	TP_POS(double x, double y)
		: X(x), Y(y)
	{}

	bool operator==(const TP_POS& pos) const
	{
		return D_EQUAL(X, pos.X) && D_EQUAL(Y, pos.Y);
	}

	bool operator!=(const TP_POS& pos) const
	{
		return !(*this == pos);
	}
};

// ����������������
struct TP_BOX 
{
	double X0;
	double Y0;	// ���Ͻ�����
	double X1;
	double Y1;	// ���½�����

	TP_BOX()
		:X0(0.0), Y0(0.0), X1(0.0), Y1(0.0)
	{}

	TP_BOX(double x0, double y0, double x1, double y1)
		: X0(x0), Y0(y0), X1(x1), Y1(y1)
	{}

	TP_BOX& operator=(const TP_BOX& box)
	{
		X0 = box.X0;
		Y0 = box.Y0;
		X1 = box.X1;
		Y1 = box.Y1;

		return *this;
	}

	bool operator==(const TP_BOX& box) const
	{
		return D_EQUAL(X0, box.X0) && D_EQUAL(Y0, box.Y0) && D_EQUAL(X1, box.X1) && D_EQUAL(Y1, box.Y1);
	}

	bool operator!=(const TP_BOX& box) const
	{
		return !(*this == box);
	}

	double Width() const
	{
		return fabs(X1 - X0);
	}

	double Height() const
	{
		return fabs(Y1 - Y0);
	}

	// �жϵ��Ƿ�λ��BOX��
	bool PosInBox(TP_POS pos) const
	{
		return (pos.X >= X0 && pos.X <= X1 && pos.Y >= Y0 && pos.Y <= Y1);
	}

	// �ж�����BOX�Ƿ��н���
	bool IsIntersect(const TP_BOX& box) const
	{
		return (X0 <= box.X1 && X1 >= box.X0 && Y0 <= box.Y1 && Y1 >= box.Y0);
	}
};

// ���ζ���
struct  TP_GLYPHMETRICS
{
	double  dWidth;
	double  dHeight;

	double  dHoriBearingX;
	double  dHoriBearingY;
	double  dHoriAdvance;

	double  dVertBearingX;
	double  dVertBearingY;
	double  dVertAdvance;

	TP_GLYPHMETRICS()
		:dWidth(0.0), dHeight(0.0), dHoriBearingX(0.0), dHoriBearingY(1.0), dHoriAdvance(0.0), dVertBearingX(0.0), dVertBearingY(0.0), dVertAdvance(0.0)
	{}

};

// ����任����
// ����任ǰ������(x_user, y_user)���任�������(x_device, y_device)���������¹�ʽ��
// x_device = x_user * matrix->M11 + y_user * matrix->M12 + matrix->M13;
// y_device = x_user * matrix->M21 + y_user * matrix->M22 + matrix->M23;
struct  TP_MATRIX
{
	double M11;
	double M21;
	double M12;
	double M22;
	double M13;
	double M23;

	TP_MATRIX()
		:M11(1.0), M21(0.0), M12(0.0), M22(1.0), M13(0.0), M23(0.0)
	{}

	TP_MATRIX(double a, double b, double c, double d, double e, double f)
		:M11(a), M21(b), M12(c), M22(d), M13(e), M23(f)
	{}

	TP_MATRIX& operator=(const TP_MATRIX& matrix)
	{
		M11 = matrix.M11;
		M21 = matrix.M21;
		M12 = matrix.M12;
		M22 = matrix.M22;
		M13 = matrix.M13;
		M23 = matrix.M23;

		return *this;
	}

	void TransformPos(TP_POS& pos)
	{
		double x = pos.X;
		double y = pos.Y;
		pos.X = x * M11 + y * M12 + M13;
		pos.Y = x * M21 + y * M22 + M23;
	}

	void TransformBox(TP_BOX& box)
	{
		double x = box.X0;
		double y = box.Y0;
		box.X0 = x * M11 + y * M12 + M13;
		box.Y0 = x * M21 + y * M22 + M23;
		x = box.X1;
		y = box.Y1;
		box.X1 = x * M11 + y * M12 + M13;
		box.Y1 = x * M21 + y * M22 + M23;

		if (box.X0 > box.X1)
		{
			x = box.X1;
			box.X1 = box.X0;
			box.X0 = x;
		}
		if (box.Y0 > box.Y1)
		{
			y = box.Y1;
			box.Y1 = box.Y0;
			box.Y0 = y;
		}
	}
};

//===========================================================================

#endif	//#ifndef __TITANDEF_HEADERFILE__
