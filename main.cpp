#include <iostream> // cin cout
#include <string.h> // c_str
#include <cstdio>
#include<vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
static int gNumOfGoal = 0 ; // �O�_���G// �ΨӬ�input���X��G 
static int gx = 0,gy = 0 ; // �ΨӬ�input���X��G 
static bool FindAllGoal = false ;
class Map {
    int startI, startJ ; // ����G���y�� 
    int endI, endJ; 
    int i ;
    int j ;
    public : vector< vector<char> > point ; // �G��Vector�s�g�c 
    public : vector< vector<char> > pointcatch ;
void pointXY( int px, int py, FILE *infile ) { // Ū�J�g�c�� 
  char num = '\0';
  int time = 0 ;
  for( j = 0 ; j < px ; j++  ) {
    point.push_back( vector<char>() );
    pointcatch.push_back( vector<char>() );
} // for 
  while( fscanf(infile," %c", &num ) != EOF ) {
  	while( num == ' ' || num== '\n' || num== '\t'  ) //���L�ťմ��� 
      fscanf(infile," %c", &num ) ;
      for( i = 0 ; i < py ; i++ ) {
  	   for( j = 0 ; j < px ; j++  ) {
  	    point[j].push_back( num )  ;
  	    pointcatch[j].push_back( num )  ;
  	    if( num == 'G')
  	      gNumOfGoal++ ; // ����g���X�� 
  	    fscanf(infile," %c", &num ) ;
      } // for
  } // for
  } // while 
  
} // pointXY

} ; //class Map

class Mouse { //�ѹ����g�c 
 private : 
  bool have = false ;
  
 public : 
   Mouse() {
   have = false ;
 }
  bool goal = false ;
 public : void run(  Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // �ѹ��q0,0�}�l�]G 
  int i = 0 ;
  int j = 0 ;
  
  map.point[0][0] = 'V' ; //�_�l��m�|���쪽���]��V 
  // cout << map.point[x+1][y] ;
  if (map.point[x][y] == 'G' ) { //���G�N�O���y�� HAVE = TRUE���X���j 
  	gx = x ;
  	gy = y ;
    have = true ;
    goal = true ;
    return ;
} // if 
  if( x +1 < rangex && ( map.point[x+1][y] == 'E' || map.point[x+1][y] == 'G' ) ) { //�@���V�k��O�_��E�ε۬OG 
    if(map.point[x+1][y] == 'E' )
      map.point[x+1][y] = 'V' ; 
    run( map,x+1, y, rangex,rangey, true, false, false, false ) ;
    if( have )
     return ;
} // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'E' || map.point[x][y+1] == 'G' ) ) { // �@���V�U��O�_��E�ε۬OG 
    if( map.point[x][y+1] == 'E' ) 
      map.point[x][y+1] = 'V' ;	
    run( map,x, y+1, rangex,rangey, false, true, false, false ) ; 
    if( have)
     return ;
  } // if
  if( x -1 >= 0 && ( map.point[x-1][y] == 'E' || map.point[x-1][y] == 'G' ) ) { //  �@���V����O�_��E�ε۬OG  
    if( map.point[x-1][y] == 'E' ) 
      map.point[x-1][y] = 'V' ;	
    run( map,x-1, y, rangex,rangey, false, false, true, false ) ;
    if( have)
     return ;
  } // if
  if( y -1 >= 0 && ( map.point[x][y-1] == 'E' || map.point[x][y-1] == 'G' ) ) { // �@���V�W��O�_��E�ε۬OG
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

 public : void runback(  Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // ����G���y�Х�G���^���_�I 
  int i = 0 ;
  int j = 0 ;
  if( x == 0 && y == 0 ) { // ����F�_�I �N�^�Ǧ^�h 
    have = true ;
    return ;
  } // if 
  if( x -1 >= 0 && ( map.point[x-1][y] == 'V' ) ) { //   �@���V����O�_��V
    if( map.point[x-1][y] == 'V' ) 
      map.point[x-1][y] = 'R';	//��V�N�令R 
    runback( map,x-1, y, rangex,rangey, false, false, true, false ) ;
    if( have)
     return ;
  } // if
  if( y- 1 >= 0 && ( map.point[x][y-1] == 'V')  ) { // �@���V�W��O�_��V
    if( map.point[x][y-1] == 'V' )
      map.point[x][y-1] = 'R' ;	//��V�N�令R 
    runback( map,x, y-1, rangex,rangey, false, false, false, true ) ;
    if( have)
     return ;
  } // if
  if( x +1 < rangex && ( map.point[x+1][y] == 'V')  ) { // �@���V�k��O�_��V 
    if(map.point[x+1][y] == 'V' )
      map.point[x+1][y] = 'R' ;   //��V�N�令R 
    runback( map,x+1, y, rangex,rangey, true, false, false, false ) ;
    if( have)
     return ;
  } // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'V') ) { // �@���V�U��O�_��V 
    if( map.point[x][y+1] == 'V' ) 
      map.point[x][y+1] = 'R'  ;	  //��V�N�令R  
    runback( map,x, y+1, rangex,rangey, false, true, false, false ) ; 
    if( have)
     return ;
  } // if  
} // runback

 public : void Printall( Map map, int rangex, int rangey ) { // �L�X�Ҧ����a�� 
       for( int i = 0 ; i < rangey ; i++ ) {
          cout << endl ;
            for( int j = 0 ; j < rangex ; j++  ) 
             cout << map.point[j][i] ;
        } // for 	
 }
 
  public : void Printall1( Map map, int rangex, int rangey ) { // ��V�令E�M��L�X�a�ϥΦb��^�_�I�� 
       for( int i = 0 ; i < rangey ; i++ ) {
          cout << endl ;
            for( int j = 0 ; j < rangex ; j++  ) {
              if( map.point[j][i] == 'V' )
                map.point[j][i] = 'E'  ; 
              cout << map.point[j][i] ;
        } // for
        } // for 	
 }

 public : bool Mission2(  int & num1,  int num, Map & map,int x, int y, int rangex,int rangey, bool right, bool left, bool up, bool down  ){ // ���ȤG���Ҧ���G�������L���| 
  int i = 0 ;
  int j = 0 ;
  bool haveve = false ; // �P�_�������O�_�����G 
  map.point[0][0] = 'V' ; 
  // cout << map.point[x+1][y] ;
  if (map.point[x][y] == 'G' ) { //���G�N�}�l�^�� 
     gx = x ;
     gy = y ;
     num1++;    
     cout << gNumOfGoal ; 
     if( (num1 == gNumOfGoal || num1 == num )  && gNumOfGoal >= num ) {  // == g�����Ʃε���Ū�J���Ʃ� g�j��Ū�J����  
       goal = true ;
       have = true ;
       Printall( map, rangex, rangey ) ; // �L�X��쪺���| 
 } // if
  if( gNumOfGoal >= num )  
     return true ;
  else 
    return false ;
  } // if 
  if( x +1 < rangex && ( map.point[x+1][y] == 'E' || map.point[x+1][y] == 'G' ) ) { //�@���V�k��O�_��E��G 
    if(map.point[x+1][y] == 'E' ) //��E�N�令V 
      map.point[x+1][y] = 'V' ; 
    haveve = Mission2( num1, num,map,x+1, y, rangex,rangey, true, false, false, false ) || haveve ; //�p�G�^�ӬOtrue�N�����û��Otrue 
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
} // if
  if( y + 1  < rangey && ( map.point[x][y+1] == 'E' || map.point[x][y+1] == 'G' ) ) { // �@���V�U��O�_��E��G 
    if( map.point[x][y+1] == 'E' ) //��E�N�令V
      map.point[x][y+1] = 'V' ;	
    haveve = Mission2( num1, num,map,x, y+1, rangex,rangey, false, true, false, false ) || haveve; //�p�G�^�ӬOtrue�N�����û��Otrue 
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
  } // if
  if( x -1 >= 0 && ( map.point[x-1][y] == 'E' || map.point[x-1][y] == 'G' ) ) { //  �@���V����O�_��E��G 
    if( map.point[x-1][y] == 'E' )  //����E�N�令V
      map.point[x-1][y] = 'V' ;
    haveve = Mission2( num1, num,map,x-1, y, rangex,rangey, false, false, true, false ) || haveve ; // �p�G�^�ӬOtrue�N�����û��Otrue  
    if( haveve )
      map.point[x][y] = 'R' ;
    if( have)
     return true ;
  } // if
  if( y -1 >= 0 && ( map.point[x][y-1] == 'E' || map.point[x][y-1] == 'G' ) ) {  //�@���V�W��O�_��E��G  
    if( map.point[x][y-1] == 'E' ) //��E�N�令V
      map.point[x][y-1] = 'V' ;	
    haveve = Mission2( num1, num,map,x, y-1, rangex,rangey, false, false, false, true ) || haveve ; // �p�G�^�ӬOtrue�N�����û��Otrue 
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
     while ( exist == false ){ // �ɮ׬O�_�}�� 
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
	    fscanf(infile,"%d %d", &rangex,&rangey ) ; //��d��Ū��� 
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
     while ( exist == false ){ // �ɮ׬O�_�}�� 
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
	    fscanf(infile,"%d %d", &rangex,&rangey ) ; //��d��Ū��� 
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
        else if( gNumOfGoal <= num ) // �p�G �A��total g �p��Ū�J���N�u�L���g 
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
