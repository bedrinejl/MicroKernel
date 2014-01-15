#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#define KEYBOARD_LAYOUT_US	(0)
#define KEYBOARD_LAYOUT_FR	(1)

#define KEYBOARD_LAYOUT_COUNT	(2)


#define VK_RSHIFT	(0x80000000)
#define VK_LSHIFT	(0x40000000)
#define VK_SHIFT	(VK_RSHIFT | VK_LSHIFT)

#define VK_RCONTROL    	(0x20000000)
#define VK_LCONTROL	(0x10000000)
#define VK_CONTROL	(VK_RCONTROL | VK_LCONTROL)

#define VK_RMENU       	(0x08000000) // ALT Key
#define VK_LMENU	(0x04000000)
#define VK_MENU		(VK_RMENU | VK_LMENU)

#define VK_KEYUP	(0x80)

#define VK_ESCAPE	(0x01)
#define VK_DEL		(0x53)
#define VK_TAB		(0x0F)
#define VK_SPACE	(0x39)
#define VK_BACKSPACE	(0x0E)
#define VK_RETURN	(0x1C)



  /*
    The uCode parameter is a virtual-key code and is translated into a scan 
    code. If it is a virtual-key code that does not distinguish between left- and 
    right-hand keys, the left-hand scan code is returned. If there is no 
    translation, the function returns 0.
  */
#define MAPVK_VK_TO_VSC		(0)

  /*
    The uCode parameter is a scan code and is translated into a virtual-key 
    code that does not distinguish between left- and right-hand keys. If there 
    is no translation, the function returns 0. 
  */
#define MAPVK_VSC_TO_VK		(1)




extern uint8_t GetScanCode(void);
uint32_t GetVirtualKey(void);
uint32_t MapVirtualKey(uint32_t uCode, uint32_t uMapType, uint32_t dwKeybordLayout);

#endif
