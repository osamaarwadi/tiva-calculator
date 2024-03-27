#ifndef lcd_h

	void ENPulse(void);
	void SendDisplayNibble(char RS_value, char bits);
	void SendDisplayCommand(char bits);
	void SendDisplayChar(char bits);
	void SendDisplayArr(char chars[]);
	void ClearDisplay (void);
	void LCD_Init(void);
#endif