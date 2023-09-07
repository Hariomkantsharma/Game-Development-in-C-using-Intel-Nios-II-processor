#include <stdio.h>
void write_pixel(int x, int y, short colour) {
  volatile short *vga_addr=(volatile short*)(0x08000000 + (y<<10) + (x<<1));
  *vga_addr=colour;
}

void clear_screen() {
  int x, y;
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
	  write_pixel(x,y,0);
	}
  }
}

void clear_screenc() {
  int x, y;
  // clear the VGA character buffer
  volatile char * character_buffer = (char *) (0x09000000);
  for (y = 0; y < 60; y++) {
    for (x = 0; x < 80; x++) {
      *(character_buffer + (y << 7) + x) = ' ';
    }
  }

  // clear the VGA pixel buffer
  volatile short *vga_addr=(volatile short*)(0x08000000);
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
      *(vga_addr + (y << 8) + x) = 0x0000;
    }
  }
}
void write_char(int x, int y, char c) {
  // VGA character buffer
  volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  *character_buffer = c;
}

void green_checks(){

int x_table[4][4]={{17,69,121,173},{43,95,147,199},{17,69,121,173},{43,95,147,199}};
int y_table[8][4];
int temp=17;

for (int i = 0; i < 8; i++)
{

    for (int j = 0; j < 4; j++)
    {
        y_table[i][j]=temp;
    }
    temp+=26;
}




for (int m = 0; m < 4; m++)
{
    for (int n = 0; n < 4; n++)
    {

        int k=x_table[m][n];
       int l= y_table[m][n];
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x07e0);
    }
    
}
    }
    
}

for (int m = 0; m < 4; m++)
{
    for (int n = 0; n < 4; n++)
    {

        int k=x_table[m][n];
       int l= y_table[m+4][n];
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x07e0);
    }
    
}
    }
    
}
}


//positon of pieces array
int position[8][8];
int xarray[8][8];
int yarray[8][8];
int position_cods[4];
int display_piece_array[17];

void position_array_cod_initial_function(int a, int b){
int tempr= a;
a=b;
b= tempr;

a= a-2;
b=b-1;
position_cods[0]=a;
position_cods[1]=b;

}
void position_array_cod_final_function(int a, int b){
int tempr= a;
a=b;
b= tempr;

a= a-2;
b=b-1;
position_cods[2]=a;
position_cods[3]=b;

}


void paint_black(int x,int y){
        int k=x;
       int l= y;
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x0000);
    }
    
}
}
void paint_green(int x,int y){
        int k=x;
       int l= y;
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x07e0);
    }
    
}
}


void hori(int x,int y,int x1,int x2,int y1){
// horizontal straight line
      for ( int i=x1;i< x2 +1;i++)
   {
      write_pixel(x+i, y+y1, 0xF81F);
   }
}
void ver(int x,int y,int x1,int y1,int y2){
   // vertical straight line
   for (int i = y1; i < y2+1; i++)
   {
       write_pixel(x+x1, y+i, 0xF81F);

   }
}
void hori_or(int x,int y,int x1,int x2,int y1){
// horizontal straight line
      for ( int i=x1;i< x2 +1;i++)
   {
      write_pixel(x+i, y+y1, 0xFD20);
   }
}
void ver_or(int x,int y,int x1,int y1,int y2){
   // vertical straight line
   for (int i = y1; i < y2+1; i++)
   {
       write_pixel(x+x1, y+i, 0xFD20);

   }
}
void black_checks(){

int x_table[4][4]={{43,95,147,199},{17,69,121,173},{43,95,147,199},{17,69,121,173}};
int y_table[8][4];
int temp=17;
for (int i = 0; i < 8; i++)
{

    for (int j = 0; j < 4; j++)
    {
        y_table[i][j]=temp;
    }
    temp+=26;
}




for (int m = 0; m < 4; m++)
{
    for (int n = 0; n < 4; n++)
    {

        int k=x_table[m][n];
       int l= y_table[m][n];
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x0000);
    }
    
}
    }
    
}

for (int m = 0; m < 4; m++)
{
    for (int n = 0; n < 4; n++)
    {

        int k=x_table[m][n];
       int l= y_table[m+4][n];
for (int i = k; i <k+ 26; i++)
{
    for (int j =l; j <l+ 26; j++)
    {
        write_pixel(i,j,0x0000);
    }
    
}
    }
    
}


}
void board_border(){
       for (int x=17;x<224;x++)
   {

      write_pixel(x, 17, 0x07e0);
      write_pixel(x, 224, 0x07e0);

}
       for (int x=17;x<224;x++)
   {

      write_pixel(17, x, 0x07e0);
      write_pixel(224, x, 0x07e0);

}


}

void pawn(int x,int y){

           // horizontal straight line
      for ( int i=x-2;i<x+3;i++)
   {
      write_pixel(i, y-4, 0xF81F);
   }
   // vertical straight line
   for (int i = 1; i < 4; i++)
   {
       write_pixel(x+3, y-i, 0xF81F);
      write_pixel(x-3, y-i, 0xF81F);

   }


   for ( int i=x-2;i<x+3;i++)
   {
      write_pixel(i, y, 0xF81F);
   }

   for (int i = 1; i < 3; i++)
   {
       write_pixel(x+2, y+i, 0xF81F);
      write_pixel(x-2, y+i, 0xF81F);

   }


// discreate pixel
      write_pixel(x+2, y+3, 0xF81F);
      write_pixel(x-2, y+3, 0xF81F);

      write_pixel(x+3, y+4, 0xF81F);
      write_pixel(x-3, y+4, 0xF81F);

      
      for ( int i=x-4;i<x+5;i++)
   {
      write_pixel(i, y+5, 0xF81F);
   }


      write_pixel(x+4, y+6, 0xF81F);
      write_pixel(x-4, y+6, 0xF81F);

      for ( int i=x-4;i<x+5;i++)
   {
      write_pixel(i, y+7, 0xF81F);
   }


   

}
void king(int x,int y){

write_pixel(x, y-6, 0xF81F);
write_pixel(x-1, y-6, 0xF81F);
write_pixel(x-1, y-3, 0xF81F);
write_pixel(x, y-3, 0xF81F);
write_pixel(x+2, y-3, 0xF81F);
write_pixel(x+3, y-3, 0xF81F);
write_pixel(x+4, y-3, 0xF81F);
write_pixel(x-5, y-3, 0xF81F);
write_pixel(x-4, y-3, 0xF81F);
write_pixel(x-3, y-3, 0xF81F);
write_pixel(x-2, y-2, 0xF81F);
write_pixel(x+1, y-2, 0xF81F);
write_pixel(x+2, y-1, 0xF81F);
write_pixel(x, y-1, 0xF81F);
write_pixel(x-3, y-1, 0xF81F);
write_pixel(x-1, y-1, 0xF81F);
write_pixel(x+1, y, 0xF81F);
write_pixel(x-2, y, 0xF81F);
write_pixel(x-4, y+1, 0xF81F);
write_pixel(x+3, y+1, 0xF81F);
write_pixel(x-3, y+2, 0xF81F);
write_pixel(x-2, y+2, 0xF81F);
write_pixel(x+1, y+2, 0xF81F);
write_pixel(x+2, y+2, 0xF81F);
write_pixel(x+3, y+4, 0xF81F);
write_pixel(x-4, y+4, 0xF81F);
write_pixel(x+4, y+6, 0xF81F);
write_pixel(x-5, y+6, 0xF81F);


ver(x,y,-2,-5,-4);
ver(x,y,1,-5,-4);
ver(x,y,5,-2,1);
ver(x,y,-6,-2,1);
ver(x,y,-5,2,3);
ver(x,y,4,2,3);
hori(x,y,-4,3,5);
hori(x,y,-5,4,7);

}
void rook(int x,int y){
    write_pixel(x-4, y-6, 0xF81F);
write_pixel(x-3, y-6, 0xF81F);
write_pixel(x-1, y-6, 0xF81F);
write_pixel(x+1, y-6, 0xF81F);
write_pixel(x, y-6, 0xF81F);
write_pixel(x+3, y-6, 0xF81F);
write_pixel(x+4, y-6, 0xF81F);
write_pixel(x-3, y-5, 0xF81F);
write_pixel(x-1, y-5, 0xF81F);
write_pixel(x+1, y-5, 0xF81F);
write_pixel(x+3, y-5, 0xF81F);
write_pixel(x-3, y-4, 0xF81F);
write_pixel(x-2, y-4, 0xF81F);
write_pixel(x-1, y-4, 0xF81F);
write_pixel(x+1, y-4, 0xF81F);
write_pixel(x+2, y-4, 0xF81F);
write_pixel(x+3, y-4, 0xF81F);
write_pixel(x+4, y, 0xF81F);
write_pixel(x-4, y, 0xF81F);

write_pixel(x+5, y+6, 0xF81F);
write_pixel(x-5, y+6, 0xF81F);

ver(x,y,5,-6,-2);
ver(x,y,-5,-6,-2);

hori(x,y,-5,5,-1);
hori(x,y,-3,3,1);

ver(x,y,3,2,4);
ver(x,y,-3,2,4);

hori(x,y,-5,5,7);
hori(x,y,-4,4,5);
}
void bishop(int x,int y){
    write_pixel(x, y-6, 0xF81F);
write_pixel(x-1, y-6, 0xF81F);
write_pixel(x-1, y-3, 0xF81F);
write_pixel(x, y-3, 0xF81F);
write_pixel(x+1, y-2, 0xF81F);
write_pixel(x-2, y-2, 0xF81F);
write_pixel(x+2, y-1, 0xF81F);
write_pixel(x-3, y-1, 0xF81F);
write_pixel(x+1, y, 0xF81F);
write_pixel(x, y+1, 0xF81F);
write_pixel(x-3, y+4, 0xF81F);
write_pixel(x+2, y+4, 0xF81F);
write_pixel(x+4, y+6, 0xF81F);
write_pixel(x-5, y+6, 0xF81F);

ver(x,y,-2,-5,-4);
ver(x,y,1,-5,-4);
ver(x,y,3,0,3);
ver(x,y,-4,0,3);
hori(x,y,-4,3,5);
hori(x,y,-5,4,7);
}
void queen(int x,int y){
    write_pixel(x, y-7, 0xF81F);
write_pixel(x+1, y-7, 0xF81F);
write_pixel(x, y-4, 0xF81F);
write_pixel(x+1, y-4, 0xF81F);
write_pixel(x-6, y-2, 0xF81F);
write_pixel(x+7, y-2, 0xF81F);
write_pixel(x+5, y-1, 0xF81F);
write_pixel(x-4, y-1, 0xF81F);
write_pixel(x+1, y-1, 0xF81F);
write_pixel(x, y-1, 0xF81F);
write_pixel(x+5, y-1, 0xF81F);
write_pixel(x+6, y-1, 0xF81F);
write_pixel(x+6, y, 0xF81F);
write_pixel(x+4, y, 0xF81F);
write_pixel(x+2, y, 0xF81F);
write_pixel(x-1, y, 0xF81F);
write_pixel(x-3, y, 0xF81F);
write_pixel(x-5, y, 0xF81F);
write_pixel(x-5, y+1, 0xF81F);
write_pixel(x-2, y+1, 0xF81F);
write_pixel(x+3, y+1, 0xF81F);
write_pixel(x+6, y+1, 0xF81F);
write_pixel(x-3, y+4, 0xF81F);
write_pixel(x+4, y+4, 0xF81F);
write_pixel(x+5, y+6, 0xF81F);
write_pixel(x-4, y+6, 0xF81F);


ver(x,y,-1,-6,-5);
ver(x,y,2,-6,-5);
ver(x,y,-1,-5,-6);
ver(x,y,2,-5,-6);
ver(x,y,-4,2,3);
ver(x,y,5,2,3);

hori(x,y,-3,4,5);
hori(x,y,-4,5,7);
}
void knight(int x,int y){
    hori(x,y,-3,0,-6);
hori(x,y,1,3,-5);
write_pixel(x-3, y-5, 0xF81F);
write_pixel(x-2, y-4, 0xF81F);
write_pixel(x+4, y-4, 0xF81F);
write_pixel(x-1, y-3, 0xF81F);
write_pixel(x-3, y-3, 0xF81F);
write_pixel(x-4, y-2, 0xF81F);
write_pixel(x-5, y-1, 0xF81F);
write_pixel(x-5, y, 0xF81F);
write_pixel(x-2, y, 0xF81F);
write_pixel(x-1, y, 0xF81F);
write_pixel(x-4, y+1, 0xF81F);
write_pixel(x-3, y+1, 0xF81F);
write_pixel(x, y+1, 0xF81F);
write_pixel(x-1, y+2, 0xF81F);
write_pixel(x-2, y+3, 0xF81F);
write_pixel(x+4, y+3, 0xF81F);
write_pixel(x-3, y+4, 0xF81F);
write_pixel(x+4, y+4, 0xF81F);
write_pixel(x+4, y+6, 0xF81F);
write_pixel(x-4, y+6, 0xF81F);


hori(x,y,-3,3,5);
hori(x,y,-4,4,7);
ver(x,y,5,-3,2);
}
void pawn_white(int x,int y){

           // horizontal straight line
      for ( int i=x-2;i<x+3;i++)
   {
      write_pixel(i, y-4, 0xFD20);
   }
   // vertical straight line
   for (int i = 1; i < 4; i++)
   {
       write_pixel(x+3, y-i, 0xFD20);
      write_pixel(x-3, y-i, 0xFD20);

   }


   for ( int i=x-2;i<x+3;i++)
   {
      write_pixel(i, y, 0xFD20);
   }

   for (int i = 1; i < 3; i++)
   {
       write_pixel(x+2, y+i, 0xFD20);
      write_pixel(x-2, y+i, 0xFD20);

   }


// discreate pixel
      write_pixel(x+2, y+3, 0xFD20);
      write_pixel(x-2, y+3, 0xFD20);

      write_pixel(x+3, y+4, 0xFD20);
      write_pixel(x-3, y+4, 0xFD20);

      
      for ( int i=x-4;i<x+5;i++)
   {
      write_pixel(i, y+5, 0xFD20);
   }


      write_pixel(x+4, y+6, 0xFD20);
      write_pixel(x-4, y+6, 0xFD20);

      for ( int i=x-4;i<x+5;i++)
   {
      write_pixel(i, y+7, 0xFD20);
   }


   

}
void king_white(int x,int y){

write_pixel(x, y-6, 0xFD20);
write_pixel(x-1, y-6, 0xFD20);
write_pixel(x-1, y-3, 0xFD20);
write_pixel(x, y-3, 0xFD20);
write_pixel(x+2, y-3, 0xFD20);
write_pixel(x+3, y-3, 0xFD20);
write_pixel(x+4, y-3, 0xFD20);
write_pixel(x-5, y-3, 0xFD20);
write_pixel(x-4, y-3, 0xFD20);
write_pixel(x-3, y-3, 0xFD20);
write_pixel(x-2, y-2, 0xFD20);
write_pixel(x+1, y-2, 0xFD20);
write_pixel(x+2, y-1, 0xFD20);
write_pixel(x, y-1, 0xFD20);
write_pixel(x-3, y-1, 0xFD20);
write_pixel(x-1, y-1, 0xFD20);
write_pixel(x+1, y, 0xFD20);
write_pixel(x-2, y, 0xFD20);
write_pixel(x-4, y+1, 0xFD20);
write_pixel(x+3, y+1, 0xFD20);
write_pixel(x-3, y+2, 0xFD20);
write_pixel(x-2, y+2, 0xFD20);
write_pixel(x+1, y+2, 0xFD20);
write_pixel(x+2, y+2, 0xFD20);
write_pixel(x+3, y+4, 0xFD20);
write_pixel(x-4, y+4, 0xFD20);
write_pixel(x+4, y+6, 0xFD20);
write_pixel(x-5, y+6, 0xFD20);


ver_or(x,y,-2,-5,-4);
ver_or(x,y,1,-5,-4);
ver_or(x,y,5,-2,1);
ver_or(x,y,-6,-2,1);
ver_or(x,y,-5,2,3);
ver_or(x,y,4,2,3);
hori_or(x,y,-4,3,5);
hori_or(x,y,-5,4,7);

}
void rook_white(int x,int y){
    write_pixel(x-4, y-6, 0xFD20);
write_pixel(x-3, y-6, 0xFD20);
write_pixel(x-1, y-6, 0xFD20);
write_pixel(x+1, y-6, 0xFD20);
write_pixel(x, y-6, 0xFD20);
write_pixel(x+3, y-6, 0xFD20);
write_pixel(x+4, y-6, 0xFD20);
write_pixel(x-3, y-5, 0xFD20);
write_pixel(x-1, y-5, 0xFD20);
write_pixel(x+1, y-5, 0xFD20);
write_pixel(x+3, y-5, 0xFD20);
write_pixel(x-3, y-4, 0xFD20);
write_pixel(x-2, y-4, 0xFD20);
write_pixel(x-1, y-4, 0xFD20);
write_pixel(x+1, y-4, 0xFD20);
write_pixel(x+2, y-4, 0xFD20);
write_pixel(x+3, y-4, 0xFD20);
write_pixel(x+4, y, 0xFD20);
write_pixel(x-4, y, 0xFD20);

write_pixel(x+5, y+6, 0xFD20);
write_pixel(x-5, y+6, 0xFD20);

ver_or(x,y,5,-6,-2);
ver_or(x,y,-5,-6,-2);

hori_or(x,y,-5,5,-1);
hori_or(x,y,-3,3,1);

ver_or(x,y,3,2,4);
ver_or(x,y,-3,2,4);

hori_or(x,y,-5,5,7);
hori_or(x,y,-4,4,5);
}
void bishop_white(int x,int y){
    write_pixel(x, y-6, 0xFD20);
write_pixel(x-1, y-6, 0xFD20);
write_pixel(x-1, y-3, 0xFD20);
write_pixel(x, y-3, 0xFD20);
write_pixel(x+1, y-2, 0xFD20);
write_pixel(x-2, y-2, 0xFD20);
write_pixel(x+2, y-1, 0xFD20);
write_pixel(x-3, y-1, 0xFD20);
write_pixel(x+1, y, 0xFD20);
write_pixel(x, y+1, 0xFD20);
write_pixel(x-3, y+4, 0xFD20);
write_pixel(x+2, y+4, 0xFD20);
write_pixel(x+4, y+6, 0xFD20);
write_pixel(x-5, y+6, 0xFD20);

ver_or(x,y,-2,-5,-4);
ver_or(x,y,1,-5,-4);
ver_or(x,y,3,0,3);
ver_or(x,y,-4,0,3);
hori_or(x,y,-4,3,5);
hori_or(x,y,-5,4,7);
}
void queen_white(int x,int y){
    write_pixel(x, y-7, 0xFD20);
write_pixel(x+1, y-7, 0xFD20);
write_pixel(x, y-4, 0xFD20);
write_pixel(x+1, y-4, 0xFD20);
write_pixel(x-6, y-2, 0xFD20);
write_pixel(x+7, y-2, 0xFD20);
write_pixel(x+5, y-1, 0xFD20);
write_pixel(x-4, y-1, 0xFD20);
write_pixel(x+1, y-1, 0xFD20);
write_pixel(x, y-1, 0xFD20);
write_pixel(x+5, y-1, 0xFD20);
write_pixel(x+6, y-1, 0xFD20);
write_pixel(x+6, y, 0xFD20);
write_pixel(x+4, y, 0xFD20);
write_pixel(x+2, y, 0xFD20);
write_pixel(x-1, y, 0xFD20);
write_pixel(x-3, y, 0xFD20);
write_pixel(x-5, y, 0xFD20);
write_pixel(x-5, y+1, 0xFD20);
write_pixel(x-2, y+1, 0xFD20);
write_pixel(x+3, y+1, 0xFD20);
write_pixel(x+6, y+1, 0xFD20);
write_pixel(x-3, y+4, 0xFD20);
write_pixel(x+4, y+4, 0xFD20);
write_pixel(x+5, y+6, 0xFD20);
write_pixel(x-4, y+6, 0xFD20);


ver_or(x,y,-1,-6,-5);
ver_or(x,y,2,-6,-5);
ver_or(x,y,-1,-5,-6);
ver_or(x,y,2,-5,-6);
ver_or(x,y,-4,2,3);
ver_or(x,y,5,2,3);

hori_or(x,y,-3,4,5);
hori_or(x,y,-4,5,7);
}
void knight_white(int x,int y){
    hori_or(x,y,-3,0,-6);
hori_or(x,y,1,3,-5);
write_pixel(x-3, y-5, 0xFD20);
write_pixel(x-2, y-4, 0xFD20);
write_pixel(x+4, y-4, 0xFD20);
write_pixel(x-1, y-3, 0xFD20);
write_pixel(x-3, y-3, 0xFD20);
write_pixel(x-4, y-2, 0xFD20);
write_pixel(x-5, y-1, 0xFD20);
write_pixel(x-5, y, 0xFD20);
write_pixel(x-2, y, 0xFD20);
write_pixel(x-1, y, 0xFD20);
write_pixel(x-4, y+1, 0xFD20);
write_pixel(x-3, y+1, 0xFD20);
write_pixel(x, y+1, 0xFD20);
write_pixel(x-1, y+2, 0xFD20);
write_pixel(x-2, y+3, 0xFD20);
write_pixel(x+4, y+3, 0xFD20);
write_pixel(x-3, y+4, 0xFD20);
write_pixel(x+4, y+4, 0xFD20);
write_pixel(x+4, y+6, 0xFD20);
write_pixel(x-4, y+6, 0xFD20);


hori_or(x,y,-3,3,5);
hori_or(x,y,-4,4,7);
ver_or(x,y,5,-3,2);
}

void game_starting(){
    rook(30,30);
rook(212,30);
knight(56,30);
knight(186,30);
bishop(82,30);
bishop(160,30);
queen(108,30);
king(134,30);
for (int i = 30; i < 224; i+=26)
{
    pawn(i,56);
}



rook_white(30,212);
rook_white(212,212);
knight_white(56,212);
knight_white(186,212);
bishop_white(82,212);
bishop_white(160,212);
queen_white(108,212);
king_white(134,212);
for (int i = 30; i < 224; i+=26)
{
    pawn_white(i,186);
}

for (int i = 0; i < 8; i++)
{
    for (int j = 0; j < 8; j++)
    {
        position[i][j]=0;
    }
    
}
position[0][0]=4;
position[0][7]=4;
position[0][1]=2;
position[0][6]=2;
position[0][2]=3;
position[0][5]=3;
position[0][3]=5;
position[0][4]=6;
for (int i = 0; i < 8; i++)
{
    position[1][i]=1;
}

position[7][0]=14;
position[7][7]=14;
position[7][1]=12;
position[7][6]=12;
position[7][2]=13;
position[7][5]=13;
position[7][3]=15;
position[7][4]=16;
for (int i = 0; i < 8; i++)
{
    position[6][i]=11;
}
queen_white(266,22);
rook_white(266,42);
pawn_white(266,62);
knight_white(302,22);
bishop_white(302,42);

queen(266,142);
rook(266,162);
pawn(266,182);
knight(302,142);
bishop(302,162);
}


void names(){
       char* name1 = "Hariom";
     int x1 = 62;
      while (*name1) {
        write_char(x1, 1, *name1);
   	 x1++;
   	 name1++;}

            char* name2 = "Abhijeet";
     int x2 = 62;
      while (*name2) {
        write_char(x2, 31, *name2);
   	 x2++;
   	 name2++;
   }
   char* name3 = "ABCDEFGH";
     int x3 = 7;
     float xsupp = 7;
      while (*name3) {
        write_char(x3, 58, *name3);
   	 xsupp+=6.5;
     int k=(int)xsupp;
     if( k==xsupp){x3= xsupp;}
     else{x3=xsupp+1;}

   	 name3++;
   }


      char* name4 = "87654321";
     int y = 7;
     float ysupp = 7;
      while (*name4) {
        write_char(2, y, *name4);
   	 ysupp+=6.5;
     int k=(int)ysupp;
     if( k==ysupp){y= ysupp;}
     else{y=ysupp+1;}

   	 name4++;
   }
//x
    write_char(67,6,'x');
    write_char(76,6,'x');
    write_char(67,11,'x');
    write_char(67,16,'x');
    write_char(76,11,'x');


        write_char(67,36,'x');
    write_char(76,36,'x');
    write_char(67,41,'x');
    write_char(67,46,'x');
    write_char(76,41,'x');
//no.


////
char queen_value= display_piece_array[5]+'0';
char knight_value= display_piece_array[2]+'0';
char rook_value= display_piece_array[4]+'0';
char bishop_value= display_piece_array[3]+'0';
char pawn_value= display_piece_array[1]+'0';

char queen_white_value= display_piece_array[15]+'0';
char knight_white_value= display_piece_array[12]+'0';
char rook_white_value= display_piece_array[14]+'0';
char bishop_white_value= display_piece_array[13]+'0';
char pawn_white_value= display_piece_array[11]+'0';
      
      
        write_char(68,6,queen_white_value);
    write_char(77,6,knight_white_value);
    write_char(68,11,rook_white_value);
    write_char(68,16,bishop_white_value);
    write_char(77,11,pawn_white_value);

        write_char(68,36,queen_value);
    write_char(77,36,knight_value);
    write_char(68,41,rook_value);
    write_char(68,46,bishop_value);
    write_char(77,41,pawn_value);
      
}
int main () {

   clear_screen();
// vertical line 240
for (int i = 0; i < 240; i++)
{
    write_pixel(241,i,0x07e0);
}
for (int i = 241; i < 321; i++)
{
    write_pixel(i,120,0x07e0);
}

green_checks();
black_checks();
board_border();


names();

game_starting();

// to print position array
for (int i = 0; i < 8; i++)
{
    for (int j = 0; j < 8; j++)
    {
        printf("%d ",position[i][j]);
    }
    printf("\n");
}


/////execution////
char a,b,c,d;
scanf("%c %c %c %c",&a,&b,&c,&d);
a=a-64;
c=c-64;
b=b-48;
d=d-48;

a= a-'0';
b= b-'0';
c= c-'0';
d= d-'0';



position_array_cod_initial_function(a,b);
position_array_cod_final_function(c,d);


int center_x_initial=xarray[position_cods[0]][position_cods[1]];
int center_y_initial=xarray[position_cods[0]][position_cods[1]];

int starting_of_box_x_initial= center_x_initial-13;
int starting_of_box_y_initial= center_y_initial-13;

int center_x_final=xarray[position_cods[2]][position_cods[3]];
int center_y_final=xarray[position_cods[2]][position_cods[3]];

int starting_of_box_x_final= center_x_final-13;
int starting_of_box_y_final= center_y_final-13;

if((a+b)%2==0){paint_black(starting_of_box_x_initial,starting_of_box_y_initial);}
else{paint_green(starting_of_box_x_initial,starting_of_box_y_initial);}

if((c+d)%2==0){paint_black(starting_of_box_x_initial,starting_of_box_y_final);}
else{paint_green(starting_of_box_x_initial,starting_of_box_y_final);}

int piece_moved= position[position_cods[0]][position_cods[1]];
position[position_cods[0]][position_cods[1]]=0;

int piece_captured= position[position_cods[2]][position_cods[3]];
position[position_cods[0]][position_cods[1]]=piece_moved;

//capturing
if(piece_captured!=0){
display_piece_array[piece_captured]++;
}


//moving the piece
switch (piece_moved)
{
case 1:
    pawn(center_x_final,center_y_final);
    break;
case 2:
    knight(center_x_final,center_y_final);
    break;
case 3:
    bishop(center_x_final,center_y_final);
    break;
case 4:
    rook(center_x_final,center_y_final);
    break;
case 5:
    queen(center_x_final,center_y_final);
    break;
case 6:
    king(center_x_final,center_y_final);
    break;

    case 11:
    pawn_white(center_x_final,center_y_final);
    break;
case 12:
    knight_white(center_x_final,center_y_final);
    break;
case 13:
    bishop_white(center_x_final,center_y_final);
    break;
case 14:
    rook_white(center_x_final,center_y_final);
    break;
case 15:
    queen_white(center_x_final,center_y_final);
    break;
case 16:
    king_white(center_x_final,center_y_final);
    break;
default:
    break;
}









//function to paint a box at k,k
// for (int i = k; i <k+ 43; i++)
// {
//     for (int j =k; j <k+ 43; j++)
//     {
//         write_pixel(i,j,0x07e0);
//     }
    
// }

   


      return 0;
}