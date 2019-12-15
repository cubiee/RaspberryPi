#include <string.h>
#include <pigpio.h>
#include "i2cLCD.h"

I2CLCD LCDInit(int id, int rows, int cols)
{
  gpioInitialise();
  I2CLCD disp;
  disp.backlight_state = LCD_BACKLIGHT_ON;
  disp.display_state = LCD_DISPLAY_ON;
  disp.cursor_state = LCD_CURSER_OFF;
  disp.row_state = 0;
  disp.col_state = 0;
  disp.bus = i2cOpen(I2C_PORT, id, 0);
  lcd_write_cmd(&disp, 0x03);
  lcd_write_cmd(&disp, 0x03);
  lcd_write_cmd(&disp, 0x03);
  lcd_write_cmd(&disp, 0x02);
  sleep(0.1);
  lcd_write_cmd(&disp, LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE);
  lcd_write_cmd(&disp, LCD_DISPLAYCONTROL | LCD_DISPLAYON);
  lcd_write_cmd(&disp, LCD_CLEARDISPLAY);
  lcd_write_cmd(&disp, LCD_ENTRYMODESET | LCD_ENTRYLEFT);
  sleep(0.2);
}

//Low level functions

//Write a single i2c command (low level function)
void write_cmd(I2CLCD *disp, int cmd)
{
  i2cWriteByte(disp->handle, cmd);
  sleep(0.0002);
}

//clocks EN to latch command (low level function)
void lcd_strobe(I2CLCD *disp, int data)
{
  write_cmd(disp, data | LCD_EN | LCD_BACKLIGHT);
  sleep(.0005);
  write_cmd(disp, ((data & ~LCD_EN) | LCD_BACKLIGHT));
  sleep(.0002);
}

//Write a nibble to the I2C bus (low level function)
void lcd_write_four_bits(I2CLCD *disp, int data)
{
  write_cmd(disp, data);
  lcd_strobe(disp, data);
}

//write command to lcd (low level function)
void lcd_write_cmd(I2CLCD *disp,int cmd)
{
  lcd_write_four_bits(disp, (cmd & 0xF0));
  lcd_write_four_bits(disp, ((cmd << 4) & 0xF0));
}

//write data to lcd (low level function)
void lcd_write_data(I2CLCD *disp, int cmd)
{
  lcd_write_four_bits(disp, LCD_RS | (cmd & 0xF0));
  lcd_write_four_bits(disp, LCD_RS | ((cmd << 4) & 0xF0));
}

//LCD functions

//put string at cursor position
void write_string(I2CLCD *disp,char *string)
{
  disp->col_state = disp->col_state + strlen(string);
  for(int i = 0; i < strlen(string), i++)
  {
    lcd_write_data(disp, string(i));
  }
}

//put string at position given by row and col
void display_string(I2CLCD *disp,char  *string, int row, int col)
{
  if(row >= disp->rows)
  {
    row = disp->rows - 1;
  }
  disp->row_state = row;
  disp->col_state = col + strlen(string);
  int row_offsets[] = {0x00, 0x40, disp->cols, 0x40 + disp->cols};
  lcd_write_cmd(LCD_SETDDRAMADDR | (row_offsets[row] + col));
  for(int i = 0; i < strlen(string), i++)
  {
    lcd_write_data(string(i));
  }
}

//set cursor position
void set_cursor(I2CLCD *disp, int row, int col)
{
  if(row >= disp->rows)
  {
    row = disp->rows - 1;
  }
  int row_offsets[] = {0x00, 0x40, disp->cols, 0x40 + disp->cols};
  disp->row_state = row;
  disp->col_state = col;
  lcd_write_cmd(disp, LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

//set cursor on
void cursor_on(I2CLCD *disp)
{
  disp->cursor_state = LCD_DISPLAY_ON;
  disp->lcd_write_cmd(LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_CURSORON);
  sleep(0.05);
}

//set cursor blinking
void cursor_blink(I2CLCD *disp)
{
  disp->cursor_state = LCD_CURSER_BLINK;
  lcd_write_cmd(disp, LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_BLINKON);
  sleep(0.05);
}

//set cursor off
void cursor_off(I2CLCD *disp)
{
  disp->cursor_state = LCD_CURSER_OFF;
  lcd_write_cmd(disp, LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF);
  sleep(0.05);
}

//set to home
void home(I2CLCD *disp)
{
  disp->row_state = 0;
  disp->col_state = 0;
  lcd_write_cmd(disp, LCD_RETURNHOME);
  
}

//clear lcd and set to home
void clear(I2CLCD *disp)
{
  disp->row_state = 0;
  disp->col_state = 0;
  lcd_write_cmd(disp, LCD_CLEARDISPLAY);
  lcd_write_cmd(disp, LCD_RETURNHOME);
  sleep(1);
}

//Move display left one position
void move_left(I2CLCD *disp)
{
  disp->col_state = disp->col_state - 1;
  lcd_write_cmd(disp, LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

//Move display right one position
void move_right(I2CLCD *disp)
{
  disp->col_state = disp->col_state + 1;
  lcd_write_cmd(disp, LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

//Switch display on
void display_on(I2CLCD *disp)
{
  disp->display_state = LCD_DISPLAY_ON;
  lcd_write_cmd(disp, LCD_DISPLAYCONTROL | LCD_DISPLAYON);
}

//Switch display off
void display_off(I2CLCD *disp)
{
  disp->display_state = LCD_DISPLAY_OFF;
  lcd_write_cmd(disp, LCD_DISPLAYCONTROL | LCD_DISPLAYOFF);
}

//Switch backlight on
void backlight_on(I2CLCD *disp)
{
  disp->backlight_state = LCD_DISPLAY_Off;
  write_cmd(disp, LCD_BACKLIGHT);
}

//Switch backlight off
void backlight_off(I2CLCD *disp)
{
  disp->backlight_state = LCD_BACKLIGHT_Off;
  write_cmd(disp, LCD_NOBACKLIGHT);
}

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
int get_backlight(I2CLCD *disp)
{
  return disp->backlight_state;
}
        
//Get display status
int get_display(I2CLCD *disp)
{
  return disp->display_state;
}
        
//Get cursor status
int get_cursor(I2CLCD *disp)
{
  return disp->cursor_state;
}
        
//Get cursor row position
int get_row_pos(I2CLCD *disp)
{
  return disp->row_state;
}
       
//Get cursor column position
int get_col_pos(I2CLCD *disp)
{
  return disp->col_state;
}