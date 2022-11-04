#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Matrix.h"
#include <iostream>


void testConstructor1Invalid1() {
		// for constructor1
		int invalid_row1 = -1, invalid_col1 = -2;

		string row1="0 0 0 \n", row2="0 0 0 \n",row3="0 0 0 \n";
			string expected=row1+row2+row3;
    // test constructor1; invalid inputs
		Matrix a = Matrix(invalid_row1,invalid_col1);

		ASSERT_EQUAL(expected,a.toString());
	}

void testConstructor1Invalid2() {
		// for constructor1
		int invalid_row2 = 1, invalid_col2 = 0;
		string expected="0 0 0 \n";
		Matrix b = Matrix(invalid_row2,invalid_col2);

		ASSERT_EQUAL(expected,b.toString());

	}

void testConstructor1Valid() {
    int valid_row = 3, valid_col = 4;
		// test constructor1; valid inputs
    string row1="0 0 0 0 \n", row2="0 0 0 0 \n",row3="0 0 0 0 \n";
    string expected=row1+row2+row3;
	Matrix d = Matrix(valid_row,valid_col);

        ASSERT_EQUAL(expected,d.toString());

	}

void testConstructor2() {
	  // for constructor2
	    int row=4,col=5;
        int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
        int*input_data[4];
        for (int i=0;i<4;i++){
        	input_data[i]=data[i];
        }
		Matrix f =  Matrix(row,col,input_data);

	    string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	    string expected=row1+row2+row3+row4;
        ASSERT_EQUAL(expected,f.toString());

}

void testGetElementValid() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f =  Matrix(row,col,input_data);

		int expected= 9;
        ASSERT_EQUAL(expected,f.getElement(1, 3));

	}


void testGetElementInvalid() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f =  Matrix(row,col,input_data);
	string actual ="Empty for Now";
	try {
			int output = f.getElement(10, 2);	// invalid indexes
	}
	catch (std::out_of_range& e){
			 actual = e.what();
	}

    string expected= "Invalid indexes.";
    ASSERT_EQUAL(expected,actual);

}

void testGetElementInvalid2() {
	  // for constructor2
    int row=3,col=4;
    int data[3][4] = {{1,2,3,4},{6,7,8,9},{76,11,1,25}};
    int*input_data[3];
    for (int i=0;i<3;i++){
    	input_data[i]=data[i];
    }
	Matrix g =  Matrix(row,col,input_data);
	string actual ="Empty for Now";
	try {
			int output = g.getElement(1, 9);	// invalid indexes
	}
	catch (std::out_of_range& e){
			 actual = e.what();
	}

    string expected= "Invalid indexes.";
    ASSERT_EQUAL(expected,actual);

}

void testGetElementInvalid3() {
	  // for constructor2
    int row=3,col=4;
    int data[3][4] = {{1,2,3,4},{6,7,8,9},{76,11,1,25}};
    int*input_data[3];
    for (int i=0;i<3;i++){
    	input_data[i]=data[i];
    }
	Matrix h =  Matrix(row,col,input_data);
	string actual ="Empty for Now";
	try {
			int output = h.getElement(-1, 2);	// invalid indexes
	}
	catch (std::out_of_range& e){
			 actual = e.what();
	}

    string expected= "Invalid indexes.";
    ASSERT_EQUAL(expected,actual);

}

void testGetElementInvalid4() {
	  // for constructor2
    int row=3,col=4;
    int data[3][4] = {{1,2,3,4},{6,7,8,9},{76,11,1,25}};
    int*input_data[3];
    for (int i=0;i<3;i++){
    	input_data[i]=data[i];
    }
	Matrix h =  Matrix(row,col,input_data);
	string actual ="Empty for Now";
	try {
			int output = h.getElement(0, -4);	// invalid indexes
	}
	catch (std::out_of_range& e){
			 actual = e.what();
	}

    string expected= "Invalid indexes.";
    ASSERT_EQUAL(expected,actual);

}


void testSetElementValid() {
	  int value = 100;
	  int setvalid_row = 0, setvalid_col = 0;
	    int row=4,col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	    int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
		Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setvalid_row,setvalid_col);
	  string row1="100 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;

      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(true,check);

	}

void testSetElementValid2() {
	  int value = 20;
	  int setvalid_row = -0, setvalid_col = 3;
	    int row=2,col=5;
	    int data[2][5] = {{1,2,3,4,5},{6,7,8,9,0}};
	    int*input_data[2];
	    for (int i=0;i<2;i++){
	    	input_data[i]=data[i];
	    }
		Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setvalid_row,setvalid_col);
	  string row1="1 2 3 20 5 \n", row2="6 7 8 9 0 \n";
	  string expected=row1+row2;

      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(true,check);

	}


void testSetElementInvalid() {
	  int value = 100;
	  int setinvalid_row = 10, setinvalid_col = 10;
	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;
      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(false,check);

}

void testSetElementInvalid2() {
	  int value = 50;
	  int setinvalid_row = -3, setinvalid_col = -1;
	  int row=3,col=4;
      int data[3][4] = {{1,2,3,4},{6,7,8,9},{0,0,1,2}};
	  int*input_data[3];
	    for (int i=0;i<3;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="1 2 3 4 \n", row2="6 7 8 9 \n", row3="0 0 1 2 \n";
	  string expected=row1+row2+row3;
      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(false,check);

}

void testCopy() {

	int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int*input_data[4];
	for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	string expected=row1+row2+row3+row4;
    ASSERT_EQUAL(expected,copied.toString());
}

void testCopy2() {

	//the third constructor is tested here as well since it is being called to create a copy within the copy function
	int row=3,col=4;
    int data[3][4] = {{1,-2,3,8/2},{6,7,8,16/8},{-0,0,1,2}};
	int*input_data[3];
	for (int i=0;i<3;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="1 -2 3 4 \n", row2="6 7 8 2 \n", row3="0 0 1 2 \n";
	string expected=row1+row2+row3;
    ASSERT_EQUAL(expected,copied.toString());
}

void testAddToInvalid() {



	   /*Add-to Matrix*/
	    int row_to_add=4; int col_to_add=3;


		int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0}, {1,2,1}}; // add to 'data' matrix, dimension not match

	 	int*add_input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	add_input_data[i]=add_to_data[i];
	 	}

	 	/*Original Matrix*/
	    int row=4;int col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	 	int*input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	input_data[i]=data[i];
	 	}
	 	Matrix origin =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Invalid operation";
        Matrix m = Matrix(row_to_add,col_to_add,add_input_data);


        try{
          m.addTo(origin);

        }
        catch (const std::invalid_argument& e) {
    	   actual = e.what();
        }
        ASSERT_EQUAL(expected,actual);
}

void testAddToInvalid2() {



	   /*Add-to Matrix*/
	    int row_to_add=3; int col_to_add=5;


		int add_to_data[3][5] = {{3,4,5,2,1}, {1,2,3,7,9}, {0,0,0,0,0}}; // add to 'data' matrix, dimension not match
		                                                                 // column dimension is not the same as 'data' matrix

	 	int*add_input_data[3];
	 	for (int i=0;i<3;i++){
	 	    	add_input_data[i]=add_to_data[i];
	 	}

	 	/*Original Matrix*/
	    int row=3;int col=4;
	    int data[3][4] = {{1,2,3,4},{6,7,8,9},{0,0,1,2}};
	 	int*input_data[3];
	 	for (int i=0;i<3;i++){
	 	    	input_data[i]=data[i];
	 	}
	 	Matrix origin =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Invalid operation";
        Matrix m = Matrix(row_to_add,col_to_add,add_input_data);


        try{
          m.addTo(origin);

        }
        catch (const std::invalid_argument& e) {
    	   actual = e.what();
        }
        ASSERT_EQUAL(expected,actual);
}


void testAddToValid() {
	   int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match
	   int add_to_above[4][3] = {{1,0,-1}, {2,1,0}, {2,2,2},{0,-1,0}}; // add to 'add_to_data' matrix
	   int row=4;int col=3;

	   int*input_data[4];
	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_data[i];
	   }
	   Matrix m =  Matrix(row,col,input_data);

	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_above[i];
	   }
	   Matrix m1 =  Matrix(row,col,input_data);
	   string row1="4 4 4 \n", row2="3 3 3 \n", row3="2 2 2 \n",row4="1 1 1 \n";
       string expected = row1+row2+row3+row4;



      try{
        m.addTo(m1);
        ASSERT_EQUAL(expected,m.toString());

      }
    catch (const std::invalid_argument& e) {
	   std::cerr << "supposed to be a valid input: " << e.what() << '\n';
    }



}

void testAddToValid2() {
	   int add_to_data[4][3] = {{3,-4/2,5}, {1,2,-3}, {-0,0,0},{1,81/3,1}}; // add to 'data' matrix, dimension not match
	   int add_to_above[4][3] = {{1,0,-1}, {2,1,0}, {2,-2,-75},{0,-1,0}}; // add to 'add_to_data' matrix
	   int row=4;int col=3;

	   int*input_data[4];
	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_data[i];
	   }
	   Matrix m =  Matrix(row,col,input_data);

	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_above[i];
	   }
	   Matrix m1 =  Matrix(row,col,input_data);
	   string row1="4 -2 4 \n", row2="3 3 -3 \n", row3="2 -2 -75 \n",row4="1 26 1 \n";
       string expected = row1+row2+row3+row4;



      try{
        m.addTo(m1);
        ASSERT_EQUAL(expected,m.toString());

      }
    catch (const std::invalid_argument& e) {
	   std::cerr << "supposed to be a valid input: " << e.what() << '\n';
    }



}




void testSubMatrixValid() {
    int subvalid_row = 3, subvalid_col = 3;


	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string row1="1 2 3 4 \n", row2="6 7 8 9 \n", row3="0 0 1 2 \n",row4="0 0 0 4 \n";
		string expected=row1+row2+row3+row4;

		try{
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);
			ASSERT_EQUAL(expected,y.toString());
		}
		catch (std::out_of_range& e){
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		}


}

void testSubMatrixValid2() {
    int subvalid_row = 1, subvalid_col = 2;


	  int row=2,col=3;
      int data[2][3] = {{1,-2,3},{-6,7,8}};
	  int*input_data[2];
	  for (int i=0;i<2;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string row1="1 -2 3 \n", row2="-6 7 8 \n"; //the submatrix is a copy of the  'data' matrix
		string expected=row1+row2;

		try{
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);
			ASSERT_EQUAL(expected,y.toString());
		}
		catch (std::out_of_range& e){
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		}


}



void testSubMatrixInvalid() {

    int subinvalid_row = 3, subinvalid_col = 6;

	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Submatrix not defined";

		try{
			Matrix y = f.subMatrix(subinvalid_row,subinvalid_col);
		}
		catch (std::out_of_range& e){

			actual = e.what();
		}
		ASSERT_EQUAL(expected,actual);


}

void testSubMatrixInvalid2() {

    int subinvalid_row = -3, subinvalid_col = 1;

	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Submatrix not defined";

		try{
			Matrix y = f.subMatrix(subinvalid_row,subinvalid_col);
		}
		catch (std::out_of_range& e){

			actual = e.what();
		}
		ASSERT_EQUAL(expected,actual);


}

void testSubMatrixInvalid3() {

    int subinvalid_row = 4, subinvalid_col = 5; //invalid row and column are the same as the 'data' matrix dimensions

	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Submatrix not defined"; //false since the size of the matrix would be 5 by 6 which is out of range of the 'data' matrix

		try{
			Matrix y = f.subMatrix(subinvalid_row,subinvalid_col);
		}
		catch (std::out_of_range& e){

			actual = e.what();
		}
		ASSERT_EQUAL(expected,actual);


}



void testIsUpperTrTrue() {
		//test isUpperTr()

	  int row=4,col=3;
      int upper1[4][3] = {{1,4,5},{0,9,8},{0,0,7},{0,0,0}};
	  int*input_upper1[4];
	  for (int i=0;i<4;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);



    bool expected = true;
    ASSERT_EQUAL(expected,v.isUpperTr());

}


void testIsUpperTrTrue2() {

	int row=2,col=4;
    int upper1[3][4] = {{3,6,9,12},{-0,2,4,6}};
	  int*input_upper1[3];
	  for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);

    bool expected = true;
    ASSERT_EQUAL(expected,v.isUpperTr());

}

void testIsUpperTrTrue3() {

	int row=3,col=2;
    int upper1[3][2] = {{3,6},{0,2},{0,0}};
	  int*input_upper1[3];
	  for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);

    bool expected = true;
    ASSERT_EQUAL(expected,v.isUpperTr());

}


void testIsUpperTrFalse() {

	int row=3,col=4;
    int upper1[3][4] = {{1,4,1,4},{0,7,6,5},{0,1,4,9}};
	  int*input_upper1[3];
	  for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);

    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}

void testIsUpperTrFalse2() {

	  int row=5,col=3;
      int upper1[5][3] = {{1,2,3},{0,5,6},{0,0,7},{0,0,0},{0,0,0}};
	  int*input_upper1[5];
	  for (int i=0;i<5;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);



    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}

void testIsUpperTrFalse3() {

	  int row=3,col=1;
      int upper1[3][1] = {{1},{2},{3}};
	  int*input_upper1[3];
	  for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);



    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}


void testIsUpperTrFalseNotSquare() {

	int row=3,col=3;
    int upper1[3][3] = {{1,4,1},{1,9,1},{0,2,4}}; // not a square matrix
	int*input_upper1[3];
	for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	}
	Matrix v =  Matrix(row,col,input_upper1);

    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}










bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
    s.push_back(CUTE(testConstructor1Invalid1));

	s.push_back(CUTE(testConstructor1Invalid2));

	s.push_back(CUTE(testConstructor1Valid));

	s.push_back(CUTE(testConstructor2));
	s.push_back(CUTE(testGetElementValid));
	s.push_back(CUTE(testGetElementInvalid));
	s.push_back(CUTE(testGetElementInvalid2));
	s.push_back(CUTE(testGetElementInvalid3));
	s.push_back(CUTE(testGetElementInvalid4));
	s.push_back(CUTE(testSetElementValid));
	s.push_back(CUTE(testSetElementValid2));
	s.push_back(CUTE(testSetElementInvalid));
	s.push_back(CUTE(testSetElementInvalid2));
	s.push_back(CUTE(testCopy));
	s.push_back(CUTE(testCopy2));
	s.push_back(CUTE(testAddToInvalid));
	s.push_back(CUTE(testAddToInvalid2));
	s.push_back(CUTE(testAddToValid));
	s.push_back(CUTE(testAddToValid2));
	s.push_back(CUTE(testSubMatrixValid));
	s.push_back(CUTE(testSubMatrixValid2));
	s.push_back(CUTE(testSubMatrixInvalid));
	s.push_back(CUTE(testSubMatrixInvalid2));
	s.push_back(CUTE(testSubMatrixInvalid3));
	s.push_back(CUTE(testIsUpperTrTrue));
	s.push_back(CUTE(testIsUpperTrTrue2));
	s.push_back(CUTE(testIsUpperTrTrue3));
	s.push_back(CUTE(testIsUpperTrFalse));
	s.push_back(CUTE(testIsUpperTrFalse2));
	s.push_back(CUTE(testIsUpperTrFalse3));
	s.push_back(CUTE(testIsUpperTrFalseNotSquare));

	//TODO add your test here

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
