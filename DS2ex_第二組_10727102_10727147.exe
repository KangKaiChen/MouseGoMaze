#include <iostream> // cin cout
#include <string.h> // c_str
#include <cstdio>
#include<vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
static int gNumOfGoal = 0 ; // 是否找到G// 用來看input有幾個G 
static int gx = 0,gy = 0 ; // 用來看input有幾個G 
static bool FindAllGoal = false ;
class Map {
    int startI, startJ ; // 紀錄G的座標 
    int endI, endJ; 
    int i ;
    int j ;
    public : vector< vector<char> > point ; // 二維Vector存迷宮 
    public : vector< vector<char> > pointcatch ;
void pointXY( int px, int py, FILE *infile ) { // 讀入迷宮圖 
  char num = '\0';
  int time = 0 ;
  for( j = 0 ; j < px ; j++  ) {
    point.push_back( vector<char>() );
    pointcatch.push_back( vector<char>() );
} // for 
  while( fscanf(infile," %c", &num ) != EOF ) {
  	while( num == ' ' || num== '\n' || num== '\t'  ) //跳過空白換行 
      fscanf(infile," %c", &num ) ;
      for( i = 0 ; i < py ; i++ ) {
  	   for( j = 0 ; j < px ; j++  ) {
  	    point[j].push_back( num )  ;
  	    pointcatch[j].push_back( num )  ;
  	    if( num == 'G')
  	      gNumOfGoal++ ; // 紀錄g有幾個 
  	    fscanf(infile," %c", &num ) ;
      } // for
  } // for
  } // while 
  
} // pointXY

} ; //class Map

class Mouse { //老鼠走迷宮 
 private : 
  bool have = false ;
  
 public : 
   Mouse() {
   have = false ;
 }
  bool goal = false ;
 public : void run(  Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // 老鼠從0,0開始跑G 
  int i = 0 ;
  int j = 0 ;
  
  map.point[0][0] = 'V' ; //起始位置會走到直接設成V 
  // cout << map.point[x+1][y] ;
  if (map.point[x][y] == 'G' ) { //找到G就記錄座標 HAVE = TRUE跳出遞迴 
  	gx = x ;
  	gy = y ;
    have = true ;
    goal = true ;
    return ;
} // if 
  if( x +1 < rangex && ( map.point[x+1][y] == 'E' || map.point[x+1][y] == 'G' ) ) { //一直向右找是否有E或著是G 
    if(map.point[x+1][y] == 'E' )
      map.point[x+1][y] = 'V' ; 
    run( map,x+1, y, rangex,rangey, true, false, false, false ) ;
    if( have )
     return ;
} // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'E' || map.point[x][y+1] == 'G' ) ) { // 一直向下找是否有E或著是G 
    if( map.point[x][y+1] == 'E' ) 
      map.point[x][y+1] = 'V' ;	
    run( map,x, y+1, rangex,rangey, false, true, false, false ) ; 
    if( have)
     return ;
  } // if
  if( x -1 >= 0 && ( map.point[x-1][y] == 'E' || map.point[x-1][y] == 'G' ) ) { //  一直向左找是否有E或著是G  
    if( map.point[x-1][y] == 'E' ) 
      map.point[x-1][y] = 'V' ;	
    run( map,x-1, y, rangex,rangey, false, false, true, false ) ;
    if( have)
     return ;
  } // if
  if( y -1 >= 0 && ( map.point[x][y-1] == 'E' || map.point[x][y-1] == 'G' ) ) { // 一直向上找是否有E或著是G
    if( map.point[x][y-1] == 'E' )
      map.point[x][y-1] = 'V' ;	
    run( map,x, y-1, rangex,rangey, false, false, false, true ) ;
    if( have)
     return ;
  } // if
 /* if( ( map.point[x+1][y] == 'V' || map.point[x+1][y] == 'O' ) && ( map.point[x][y+1] == 'V' || map.point[x][y+1] == 'O' 
     ) && ( map.point[x-1][y] == 'V' || map.point[x-1][y] == 'O' ) && ( map.point[x][y-1] == 'V' || map.point[x][y-1] == 'O' ) ) {
    return ;
	 } */  
 
   
} // run

 public : void runback(  Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // 紀錄G的座標由G往回找到起點 
  int i = 0 ;
  int j = 0 ;
  if( x == 0 && y == 0 ) { // 走到了起點 就回傳回去 
    have = true ;
    return ;
  } // if 
  if( x -1 >= 0 && ( map.point[x-1][y] == 'V' ) ) { //   一直向左找是否有V
    if( map.point[x-1][y] == 'V' ) 
      map.point[x-1][y] = 'R';	//有V就改成R 
    runback( map,x-1, y, rangex,rangey, false, false, true, false ) ;
    if( have)
     return ;
  } // if
  if( y- 1 >= 0 && ( map.point[x][y-1] == 'V')  ) { // 一直向上找是否有V
    if( map.point[x][y-1] == 'V' )
      map.point[x][y-1] = 'R' ;	//有V就改成R 
    runback( map,x, y-1, rangex,rangey, false, false, false, true ) ;
    if( have)
     return ;
  } // if
  if( x +1 < rangex && ( map.point[x+1][y] == 'V')  ) { // 一直向右找是否有V 
    if(map.point[x+1][y] == 'V' )
      map.point[x+1][y] = 'R' ;   //有V就改成R 
    runback( map,x+1, y, rangex,rangey, true, false, false, false ) ;
    if( have)
     return ;
  } // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'V') ) { // 一直向下找是否有V 
    if( map.point[x][y+1] == 'V' ) 
      map.point[x][y+1] = 'R'  ;	  //有V就改成R  
    runback( map,x, y+1, rangex,rangey, false, true, false, false ) ; 
    if( have)
     return ;
  } // if  
} // runback

 public : void Printall( Map map, int rangex, int rangey ) { // 印出所有的地圖 
       for( int i = 0 ; i < rangey ; i++ ) {
          cout << endl ;
            for( int j = 0 ; j < rangex ; j++  ) 
             cout << map.point[j][i] ;
        } // for 	
 }
 
  public : void Printall1( Map map, int rangex, int rangey ) { // 把V改成E然後印出地圖用在找回起點時 
       for( int i = 0 ; i < rangey ; i++ ) {
          cout << endl ;
            for( int j = 0 ; j < rangex ; j++  ) {
              if( map.point[j][i] == 'V' )
                map.point[j][i] = 'E'  ; 
              cout << map.point[j][i] ;
        } // for
        } // for 	
 }

 public : bool Mission2(  int & num1,  int num, Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // 任務二找到所有的G紀錄走過路徑 
  int i = 0 ;
  int j = 0 ;
  bool haveve = false ; // 判斷那條路是否有找到G 
  map.point[0][0] = 'V' ; 
  // cout << map.point[x+1][y] ;
  if (map.point[x][y] == 'G' ) { //找到G就開始回傳 
     gx = x ;
     gy = y ;
     num1++;    
     cout << gNumOfGoal ; 
     if( (num1 == gNumOfGoal || num1 == num )  && gNumOfGoal >= num ) {  // == g的次數或等於讀入次數或 g大於讀入次數  
       goal = true ;
       have = true ;
       Printall( map, rangex, rangey ) ; // 印出找到的路徑 
 } // if
  if( gNumOfGoal >= num )  
     return true ;
  else 
    return false ;
  } // if 
  if( x +1 < rangex && ( map.point[x+1][y] == 'E' || map.point[x+1][y] == 'G' ) ) { //一直向右找是否有E或G 
    if(map.point[x+1][y] == 'E' ) //有E就改成V 
      map.point[x+1][y] = 'V' ; 
    haveve = Mission2( num1, num,map,x+1, y, rangex,rangey, true, false, false, false ) || haveve ; //如果回來是true就讓它永遠是true 
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
} // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'E' || map.point[x][y+1] == 'G' ) ) { // 一直向下找是否有E或G 
    if( map.point[x][y+1] == 'E' ) //有E就改成V
      map.point[x][y+1] = 'V' ;	
    haveve = Mission2( num1, num,map,x, y+1, rangex,rangey, false, true, false, false ) || haveve; //如果回來是true就讓它永遠是true 
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
  } // if
  if( x -1 >= 0 && ( map.point[x-1][y] == 'E' || map.point[x-1][y] == 'G' ) ) { //  一直向左找是否有E或G 
    if( map.point[x-1][y] == 'E' )  //有有E就改成V
      map.point[x-1][y] = 'V' ;
    haveve = Mission2( num1, num,map,x-1, y, rangex,rangey, false, false, true, false ) || haveve ; // 如果回來是true就讓它永遠是true  
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
  } // if
  if( y -1 >= 0 && ( map.point[x][y-1] == 'E' || map.point[x][y-1] == 'G' ) ) {  //一直向上找是否有E或G  
    if( map.point[x][y-1] == 'E' ) //有E就改成V
      map.point[x][y-1] = 'V' ;	
    haveve = Mission2( num1, num,map,x, y-1, rangex,rangey, false, false, false, true ) || haveve ; // 如果回來是true就讓它永遠是true 
    if( haveve ) 
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
  } // if

  return haveve ;
} // Mission2

}; // class Mouse
int main(int argc, char** argv) {
      int command = 0 ;
      cout << endl << "**** Path Finding *****";
      cout << endl << "* 0. Quit *";
      cout << endl << "* 1. One goal *";
      cout << endl << "* 2. More goals *";
      cout << endl << "*******************************";
      cout << endl << "Input a command(0, 1, 2): ";	 
      cin >> command ; 
      cout << endl ;
    do {
      bool exist = false ;
      string filename = "" ;
      string usefilename = "" ;
      bool right = false ;
       bool left = false;
       bool up = false;
      bool down = false;
      int num = 0 ;
      int num1 = 0 ; 
      int rangex = 0,rangey = 0 ;
      int x = 0,y = 0 ;
      Map map = Map();
      Mouse run = Mouse() ;
      FILE *infile = NULL  ;
   	if ( command == 1 ) {
     cout << "Input a file number (e.g., 201, 202, 203, ...):" ;
    cin >> filename ;
     cout << endl ; 
      usefilename ="input" + filename + ".txt" ;
     char *cs = new char[usefilename.length() + 1 ] ;
     strcpy( cs, usefilename.c_str() ) ;
     while ( exist == false ){ // 檔案是否開啟 
       infile = fopen(usefilename.c_str(),"r") ;
	   if (infile == NULL ){
	    cout << "###"+ usefilename + "does not exist! ###" << endl ;
	    fclose( infile ) ;
        cout << "Command does not exist!" << endl ;
        cout << endl << "**** Path Finding *****";
        cout << endl << "* 0. Quit *";
        cout << endl << "* 1. One goal *";
        cout << endl << "* 2. More goals *";
        cout << endl << "*******************************";
        cout << endl << "Input a command(0, 1, 2): ";	 
        cin >> command ; 
        cout << endl ;
    	} // if
	   else {
	    exist = true ;
	    fscanf(infile,"%d %d", &rangex,&rangey ) ; //把範圍讀近來 
	} // else 	
  } // while 
	  map.pointXY( rangex, rangey, infile ) ;
      run.run( map, x, y, rangex, rangey, right, left, up, down ) ;
       run.Printall( map, rangex, rangey );
        cout << endl << endl ;
        x = gx ;
        y = gy ;  
        run.runback( map, x, y, rangex, rangey, right, left, up, down ) ;
        if( run.goal == true && gNumOfGoal >= num  )
          run.Printall1( map, rangex, rangey );
        gNumOfGoal = 0 ;
	} // if
	if ( command == 2 ) {
     cout << "Input a file number (e.g., 201, 202, 203, ...):" ;
    cin >> filename ;
      usefilename ="input" + filename + ".txt" ;
     char *cs = new char[usefilename.length() + 1 ] ;
     strcpy( cs, usefilename.c_str() ) ;
     while ( exist == false ){ // 檔案是否開啟 
       infile = fopen(usefilename.c_str(),"r") ;
	   if (infile == NULL ){
	    cout << "###"+ usefilename + "does not exist! ###\n";
	    fclose( infile ) ;
        cout << "Command does not exist!" << endl ;
      cout << endl << "**** Path Finding *****";
      cout << endl << "* 0. Quit *";
      cout << endl << "* 1. One goal *";
      cout << endl << "* 2. More goals *";
      cout << endl << "*******************************";
      cout << endl << "Input a command(0, 1, 2): ";	 
      cin >> command ; 
      cout << endl ;
    	} // if
	   else {
	    exist = true ;
	    fscanf(infile,"%d %d", &rangex,&rangey ) ; //把範圍讀近來 
	} // else 	
  } // while 
	  map.pointXY( rangex, rangey, infile ) ;	
	  cout << "Number of G (goals):" ;
      cin >> num ; 
	    x = 0 ;
	    y = 0 ; 

        if( run.Mission2( num1, num,map, x, y, rangex, rangey, right, left, up, down ) == true  ) {
          if( gNumOfGoal >= num ) {
            cout << endl << endl ; 
          run.Printall1( map, rangex, rangey );
      } // if
        } // if 
        else if( gNumOfGoal <= num ) // 如果 你的total g 小於讀入的就只印找到g 
          run.Printall( map, rangex, rangey );
        gNumOfGoal = 0 ;
    } // if
    else 
    cout << "Command does not exist!" << endl ;
      cout << endl << "**** Path Finding *****";
      cout << endl << "* 0. Quit *";
      cout << endl << "* 1. One goal *";
      cout << endl << "* 2. More goals *";
      cout << endl << "*******************************";
      cout << endl << "Input a command(0, 1, 2): ";	 
      cin >> command ; 
      cout << endl ;
  } while( command != 0 ) ;
}
