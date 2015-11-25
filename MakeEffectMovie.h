//////////
//
//	File:		MakeEffectMovie.h
//
//	Contains:	QuickTime video effect support for QuickTime movies.
//				This file is used for BOTH MacOS and Windows.
//
//	Written by:	Tim Monroe
//				Based (heavily!) on the previous MakeEffectMovie code written by Sam Bushell.
//
//	Copyright:	� 1997-1998 by Apple Computer, Inc., all rights reserved.
//
//	Change History (most recent first):
//
//	   <1>	 	11/06/97	rtm		first file; integrated existing code with shell framework
//	   
//////////

//////////
//
// header files
//
//////////

#include <ImageCodec.h>

#if TARGET_OS_MAC
#include "MacFramework.h"
#endif

#if TARGET_OS_WIN32
#include "WinFramework.h"
#endif


//////////
//
// compiler flags and macros
//
//////////

#define USES_MAKE_IMAGE_DESC_FOR_EFFECT	1		// use MakeImageDescriptionForEffect (QT 4.0 and later)

#define	BailNil(n)						if (!n) { if (!myErr) myErr = -1; goto bail; }
#define	BailError(n)					if (n) { if (!myErr) myErr = -1; goto bail; }


//////////
//
// constants
//
//////////

#define kMaxNumSources					2		// the maximum number of input tracks we will collect

#define kNoSourceName					FOUR_CHAR_CODE('none')
#define kSourceOneName					FOUR_CHAR_CODE('srcA')
#define kSourceTwoName					FOUR_CHAR_CODE('srcB')

#define kDefaultFramesPerSecond			15		// the default playback rate of the video effects track

#define kEffectsSaveMoviePrompt			"Save Effect Movie File As:"
#define kEffectsSaveMovieFileName		"untitled.mov"


//////////
//
// function prototypes
//
//////////

OSErr								QTEffects_GetFirstVideoTrackInMovie (Movie theMovie, Track *theTrack);
OSErr								QTEffects_DisplayDialogForSources (FSSpec *theSpecList, UInt16 theSpecCount);
void								QTEffects_RespondToDialogSelection (OSErr theErr);
#if TARGET_OS_WIN32
static void							QTEffects_EffectsDialogCallback (EventRecord *theEvent, DialogRef theDialog, DialogItemIndex theItemHit);
LRESULT CALLBACK					QTEffects_CustomDialogWndProc (HWND theWnd, UINT theMessage, UINT wParam, LONG lParam);
#endif
Boolean								QTEffects_HandleEffectsDialogEvents (EventRecord *theEvent, DialogItemIndex theItemHit);
void								QTEffects_PromptUserForFilesAndMakeEffect (void);
