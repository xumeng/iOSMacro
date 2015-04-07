//
//  iOSMacro.h
//  iOSMacro
//
//  Created by Amon on 4/1/15.
//  Copyright (c) 2015 Amon. All rights reserved.
//

#ifndef iOSMacro_iOSMacro_h
#define iOSMacro_iOSMacro_h

//  Path about Sandbox
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

//  DEBUG模式下 设置NSZombieEnabled==YES 如果crash打印错误信息
#if DEBUG

#define Debug() printf("%s %s %d\n",\
__FILE__,__func__,__LINE__);

#else

#define Debug()

#endif

/* ****************************************************************************************************************** */
/** DEBUG LOG **/
#if DEBUG
#   define DLog(fmt, ...)   do{NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}while(0)
#else
#   define DLog(...)    do{}while(0)
#endif

//  重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT,...) do{ \
fprintf(stderr,"<%s : %d > %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],__LINE__,__func__);\
(NSLog)((FORMAT),##__VA_ARGS__); \
fprintf(stderr,"---------------\n");\
}while(0)
#else
#define NSLog(FORMAT,...) do{ }while(0)
#endif

//  DEBUG  模式下打印日志,当前行 并弹出一个警告
#if DEBUG
#define ULog(fmt, ...)   do{ UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }while(0)
#else
#define ULog(...)    do{ }while(0)
#endif

/** DEBUG RELEASE **/
#if DEBUG

#define MCRelease(x)            [x release]

#else

#define MCRelease(x)            [x release], x = nil

#endif


/** NIL RELEASE **/
#define NILRelease(x)           [x release], x = nil


/* ****************************************************************************************************************** */
#pragma mark - Frame (宏 x, y, width, height)

//  App Frame
#define Application_Frame       [[UIScreen mainScreen] applicationFrame]

//  App Frame Height&Width
#define App_Frame_Height        [[UIScreen mainScreen] applicationFrame].size.height
#define App_Frame_Width         [[UIScreen mainScreen] applicationFrame].size.width

//  MainScreen Height&Width
#define Main_Screen_Height      [[UIScreen mainScreen] bounds].size.height
#define Main_Screen_Width       [[UIScreen mainScreen] bounds].size.width

//  View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y
#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height

#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

//  系统控件默认高度
#define kACStatusBarHeight        (20.f)

#define kACTopBarHeight           (44.f)
#define kACBottomBarHeight        (49.f)

#define kACCellDefaultHeight      (44.f)

#define kACEnglishKeyboardHeight  (216.f)
#define kACChineseKeyboardHeight  (252.f)


/* ****************************************************************************************************************** */
#pragma mark - Funtion Method (宏 方法)

//  PNG JPG 图片路径
#define PNGPATH(NAME)           [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"png"]
#define JPGPATH(NAME)           [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"jpg"]
#define PATH(NAME, EXT)         [[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]

//  加载图片
#define PNGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGE(NAME, EXT)        [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]
#define ImageNamed(NAME)        [UIImage imageNamed:(NAME)]

//  建议使用前一种宏定义,性能高于后者
//----------------------图片----------------------------


//  字体大小(常规/粗体)
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]

//  颜色(RGB)
#define RGBCOLOR(r, g, b)       [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r, g, b, a)   [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
//  RGB颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]


//  View 圆角和加边框并裁剪子视图
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//  View 圆角+阴影 但不能裁剪子视图
#define ViewRadiusWithShadow(View,Radius,ShadowColor,ShadowRadius,ShadowOpacity,ShadowOffset)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setShadowColor:[ShadowColor CGColor]];\
[View.layer setShadowRadius:(ShadowRadius)];\
[View.layer setShadowOpacity:(ShadowOpacity)];\
[View.layer setShadowOffset:ShadowOffset];\
[View.layer setShadowPath:[UIBezierPath bezierPathWithRoundedRect:View.bounds cornerRadius:View.layer.cornerRadius].CGPath];\
[View.layer setMasksToBounds:NO]

//  View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

//  当前设备的系统版本
#define FSystemVersion          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define DSystemVersion          ([[[UIDevice currentDevice] systemVersion] doubleValue])
#define SSystemVersion          ([[UIDevice currentDevice] systemVersion])

//  当前语言
#define CURRENTLANGUAGE         ([[NSLocale preferredLanguages] objectAtIndex:0])
//  App的本地版本:对外/对内
#define APPLOCATIONVERSION_External      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define APPLOCATIONVERSION_Internal      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

//  是否Retina屏
#define isRetina                ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
CGSizeEqualToSize(CGSizeMake(640, 960), \
[[UIScreen mainScreen] currentMode].size) : \
NO)

//  是否iPhone5
#define isiPhone5               ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
CGSizeEqualToSize(CGSizeMake(640, 1136), \
[[UIScreen mainScreen] currentMode].size) : \
NO)

//  UIView - viewWithTag
#define VIEWWITHTAG(_OBJECT, _TAG)\
\
[_OBJECT viewWithTag : _TAG]

//  本地化字符串
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define LocalString(x, ...)     NSLocalizedString(x, nil)
/** NSLocalizedStringFromTable宏做的其实就是在当前bundle中查找资源文件名“xxx.strings”(参数:键＋文件名＋注释) */
#define AppLocalString(x, ...)  NSLocalizedStringFromTable(x, @"someName", nil)


#if TARGET_OS_IPHONE
/** iPhone Device */
#endif

#if TARGET_IPHONE_SIMULATOR
/** iPhone Simulator */
#endif

//----------------------内存----------------------------
//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#define SAFE_RELEASE(P)      do{ if(P) { P = nil; } }while(0)
#else
// compiling without ARC
#define SAFE_RELEASE(P)      do{ if(P) { [P release], P = nil; } }while(0)
#endif

/* ****************************************************************************************************************** */
#pragma mark - Log Method (宏 LOG)

//  日志 / 断点
// =============================================================================================================================
//  DEBUG模式
#define ITTDEBUG

//  LOG等级
#define ITTLOGLEVEL_INFO        10
#define ITTLOGLEVEL_WARNING     3
#define ITTLOGLEVEL_ERROR       1

// =============================================================================================================================
//  LOG最高等级
#ifndef ITTMAXLOGLEVEL

#ifdef DEBUG
#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO
#else
#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR
#endif

#endif

//   ============================================================================================================= ================
//   LOG PRINT
//   The general purpose logger. This ignores logging levels.
#ifdef ITTDEBUG
#define ITTDPRINT(xx, ...)      NSLog(@"< %s:(%d) > : " xx , __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define ITTDPRINT(xx, ...)      ((void)0)
#endif

//  Prints the current method's name.
#define ITTDPRINTMETHODNAME()   ITTDPRINT(@"%s", __PRETTY_FUNCTION__)

//  Log-level based logging macros.
#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
#define ITTDERROR(xx, ...)      ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDERROR(xx, ...)      ((void)0)
#endif

#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
#define ITTDWARNING(xx, ...)    ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDWARNING(xx, ...)    ((void)0)
#endif

#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
#define ITTDINFO(xx, ...)       ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDINFO(xx, ...)       ((void)0)
#endif

//  条件LOG
#ifdef ITTDEBUG
#define ITTDCONDITIONLOG(condition, xx, ...)\
\
{\
if ((condition))\
{\
ITTDPRINT(xx, ##__VA_ARGS__);\
}\
}
#else
#define ITTDCONDITIONLOG(condition, xx, ...)\
\
((void)0)
#endif

//  断点Assert
#define ITTAssert(condition, ...)\
\
do {\
if (!(condition))\
{\
[[NSAssertionHandler currentHandler]\
handleFailureInFunction:[NSString stringWithFormat:@"< %s >", __PRETTY_FUNCTION__]\
file:[[NSString stringWithUTF8String:__FILE__] lastPathComponent]\
lineNumber:__LINE__\
description:__VA_ARGS__];\
}\
} while(0)

//  G－C－D
#define BACK(block)     dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block)     dispatch_async(dispatch_get_main_queue(),block)

//  由角度获取弧度 有弧度获取角度
#define degreesToRadian(x)          (M_PI * (x) / 180.0)
#define radianToDegrees(radian)     (radian*180.0)/(M_PI)

/* ****************************************************************************************************************** */
#pragma mark - Constants (宏 常量)


/** 时间间隔 */
#define kHUDDuration            (1.f)

/** 一天的秒数 */
#define SecondsOfDay            (24.f * 60.f * 60.f)
/** 秒数 */
#define Seconds(Days)           (24.f * 60.f * 60.f * (Days))

/** 一天的毫秒数 */
#define MillisecondsOfDay       (24.f * 60.f * 60.f * 1000.f)
/** 毫秒数 */
#define Milliseconds(Days)      (24.f * 60.f * 60.f * 1000.f * (Days))


//** textAlignment ***********************************************************************************

#if !defined __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_5_0
# define LineBreakMode                  UILineBreakMode
# define LineBreakModeWordWrap          UILineBreakModeWordWrap
# define LineBreakModeCharacterWrap     UILineBreakModeCharacterWrap
# define LineBreakModeClip              UILineBreakModeClip
# define LineBreakModeHeadTruncation    UILineBreakModeHeadTruncation
# define LineBreakModeTailTruncation    UILineBreakModeTailTruncation
# define LineBreakModeMiddleTruncation  UILineBreakModeMiddleTruncation

# define TextAlignment                  UITextAlignment
# define TextAlignmentLeft              UITextAlignmentLeft
# define TextAlignmentCenter            UITextAlignmentCenter
# define TextAlignmentRight             UITextAlignmentRight

#else
# define LineBreakMode                  NSLineBreakMode
# define LineBreakModeWordWrap          NSLineBreakByWordWrapping
# define LineBreakModeCharacterWrap     NSLineBreakByCharWrapping
# define LineBreakModeClip              NSLineBreakByClipping
# define LineBreakModeHeadTruncation    NSLineBreakByTruncatingHead
# define LineBreakModeTailTruncation    NSLineBreakByTruncatingTail
# define LineBreakModeMiddleTruncation  NSLineBreakByTruncatingMiddle

# define TextAlignment                  NSTextAlignment
# define TextAlignmentLeft              NSTextAlignmentLeft
# define TextAlignmentCenter            NSTextAlignmentCenter
# define TextAlignmentRight             NSTextAlignmentRight

#endif

//  单例化一个类
#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil;\
\
+ (classname *)shared##classname\
{\
@synchronized(self)\
{\
if (shared##classname == nil)\
{\
shared##classname = [[self alloc] init];\
}\
}\
\
return shared##classname;\
}\
\
+ (id)allocWithZone:(NSZone *)zone\
{\
@synchronized(self)\
{\
if (shared##classname == nil)\
{\
shared##classname = [super allocWithZone:zone];\
return shared##classname;\
}\
}\
\
return nil;\
}\
\
- (id)copyWithZone:(NSZone *)zone\
{\
return self;\
}


#endif
