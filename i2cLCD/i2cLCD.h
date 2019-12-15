#ifndef I2CLCD_H
#define I2CLCD_H

//define display on off 
#define LCD_DISPLAY_ON        1
#define LCD_DISPLAY_Off       0

//define backlight on off
#define LCD_BACKLIGHT_ON      1
#define LCD_BACKLIGHT_Off     0

//define cursor on off
#define LCD_CURSER_BLINK      2
#define LCD_CURSER_ON         1
#define LCD_CURSER_OFF        0

//I2C-Bus Port (raspberry default = 1)
#define I2C_PORT              1

//commands
#define LCD_CLEARDISPLAY   0x01
#define LCD_RETURNHOME     0x02
#define LCD_ENTRYMODESET   0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT    0x10
#define LCD_FUNCTIONSET    0x20
#define LCD_SETCGRAMADDR   0x40
#define LCD_SETDDRAMADDR   0x80

//flags for display entry mode
#define LCD_ENTRYRIGHT     0x00
#define LCD_ENTRYLEFT      0x02

//flags for display on/off control
#define LCD_DISPLAYON      0x04
#define LCD_DISPLAYOFF     0x00
#define LCD_CURSORON       0x02
#define LCD_CURSOROFF      0x00
#define LCD_BLINKON        0x01
#define LCD_BLINKOFF       0x00

//flags for display/cursor shift
#define LCD_DISPLAYMOVE    0x08
#define LCD_CURSORMOVE     0x00
#define LCD_MOVERIGHT      0x04
#define LCD_MOVELEFT       0x00

//flags for function set
#define LCD_8BITMODE       0x10
#define LCD_4BITMODE       0x00
#define LCD_2LINE          0x08
#define LCD_1LINE          0x00
#define LCD_5x10DOTS       0x04
#define LCD_5x8DOTS        0x00

//flags for backlight control
#define LCD_BACKLIGHT      0x08
#define LCD_NOBACKLIGHT    0x00

//control bits
//Enable bit
#define LCD_EN             0x04 
//Register select bit
#define LCD_RS             0x01

typedef struct i2clcd_s
{
  int addr;
  int rows;
  int cols;
  int backlight_state;
  int display_state;
  int cursor_state;
  int row_state;
  int col_state;
  int handle;
} I2CLCD;

I2CLCD i2cLCDInit(int id, int rows, int cols);

//Low level functions
//Write a single i2c command (low level function)
void write_cmd(I2CLCD *disp, int cmd);

//clocks EN to latch command (low level function)
void lcd_strobe(I2CLCD *disp, int data);

//Write a nibble to the I2C bus (low level function)
void lcd_write_four_bits(I2CLCD *disp, int data);

//write command to lcd (low level function)
void lcd_write_cmd(I2CLCD *disp,int cmd);

//write data to lcd (low level function)
void lcd_write_data(I2CLCD *disp, int cmd);

//LCD functions

//put string at cursor position
void write_string(I2CLCD *disp,char *string);

//put string at position given by row and col
void display_string(I2CLCD *disp,char  *string, int row, int col);

//set cursor position
void set_cursor(I2CLCD *disp, int row, int col);

//set cursor on
void cursor_on(I2CLCD *disp);

//set cursor blinking
void cursor_blink(I2CLCD *disp);

//set cursor off
void cursor_off(I2CLCD *disp);

//set to home
void home(I2CLCD *disp);

//clear lcd and set to home
void clear(I2CLCD *disp);

//Move display left one position
void move_left(I2CLCD *disp);

//Move display right one position
void move_right(I2CLCD *disp);

//Switch display on
void display_on(I2CLCD *disp);

//Switch display off
void display_off(I2CLCD *disp);

//Switch backlight on
void backlight_on(I2CLCD *disp);

//Switch backlight off
void backlight_off(I2CLCD *disp);

//Fill one of the first 8 CGRAM locations with custom characters.
//The location parameter must be between 0 and 7 and pattern must
//provide an array of 8 bytes containing the pattern.
//    def create_char(self, location, pattern):
//        //only position 0..7 are allowed
//        location &= 0x7
//        self.lcd_write_cmd(LCD_SETCGRAMADDR | (location << 3))
//        for i in range(8):
//            self.lcd_write_data(pattern[i])

//Get backlight status
int get_backlight(I2CLCD *disp);
        
//Get display status
int get_display(I2CLCD *disp);
        
//Get cursor status
int get_cursor(I2CLCD *disp);
        
//Get cursor row position
int get_row_pos(I2CLCD *disp);
       
//Get cursor column position
int get_col_pos(I2CLCD *disp);

#endif