#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/xml_listener.h"
#include "cute/cute_runner.h"
//#include "Matrix.h"
#include "SLLSet.h"
#include <iostream>





void testSLLSet() {



        //test constructor 1
        SLLSet listObj1 = SLLSet();
        string expectedSet = "";
        int expectedSize = 0;
        ASSERT_EQUAL(expectedSize,listObj1.getSize());
        ASSERT_EQUAL(expectedSet,listObj1.toString());
	}


void testSLLSetIntArray() {

        int arr[] = {1, 2, 3, 7, 8}; // this list

        SLLSet listObj2 = SLLSet(arr,5);
        string expectedSet = "1, 2, 3, 7, 8";
        int expectedSize = 5;
        ASSERT_EQUAL(expectedSize,listObj2.getSize());
        ASSERT_EQUAL(expectedSet,listObj2.toString());
	}

void testSLLSetIntArray_Empty() {

        int arr[] = {}; // this list

        SLLSet listObj2 = SLLSet(arr,0);
        string expectedSet = "";
        int expectedSize = 0;
        ASSERT_EQUAL(expectedSize,listObj2.getSize());
        ASSERT_EQUAL(expectedSet,listObj2.toString());
	}




void testCopy() {

        int arr[] = {1, 2, 3, 7, 8}; // this list
        SLLSet listObj2 =  SLLSet(arr,5);
		SLLSet copied = listObj2.copy();
        copied.add(100);
        string expectedObj2 = "1, 2, 3, 7, 8";
        string expectedCopied = "1, 2, 3, 7, 8, 100";
        int expectedObj2Size = 5;
        int expectedCopiedSize = 6;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());

        ASSERT_EQUAL(expectedCopiedSize,copied.getSize());
        ASSERT_EQUAL(expectedCopied,copied.toString());


	}

void testCopy2() {

	    //create a copy after removing an element from the set

        int arr[] = {10, 20, 30, 40}; // this list
        SLLSet listObj2 =  SLLSet(arr,4);
		SLLSet copied = listObj2.copy();
        copied.remove(20);
        string expectedObj2 = "10, 20, 30, 40";
        string expectedCopied = "10, 30, 40";
        int expectedObj2Size = 4;
        int expectedCopiedSize = 3;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());

        ASSERT_EQUAL(expectedCopiedSize,copied.getSize());
        ASSERT_EQUAL(expectedCopied,copied.toString());


	}

void testCopy3() {

	    //create a copy if both sets are empty

        int arr[] = {}; // this list
        SLLSet listObj2 =  SLLSet(arr,0);
		SLLSet copied = listObj2.copy();
        string expectedObj2 = "";
        string expectedCopied = "";
        int expectedObj2Size = 0;
        int expectedCopiedSize = 0;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());

        ASSERT_EQUAL(expectedCopiedSize,copied.getSize());
        ASSERT_EQUAL(expectedCopied,copied.toString());


	}


void testIsInTrue() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int in = 2;

        bool expected = true;

        ASSERT_EQUAL(expected,listObj2.isIn(in));


	}


void testIsInFalse() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int notin = 0; // test isIn
        bool expected = false;

        ASSERT_EQUAL(expected,listObj2.isIn(notin));

	}

void testIsInFraction() {

	//tests to see if the value is found when it is an equivalent fraction

    int arr[] = {10, 20, 80/2, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);

        int in = 40;

        bool expected = true;

        ASSERT_EQUAL(expected,listObj2.isIn(in));


	}

void testIsInNegative() {

	//tests to see if a value is found when there is a negative number in the set

    int arr[] = {-15, 10, 40, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);

        int in = 40;

        bool expected = true;

        ASSERT_EQUAL(expected,listObj2.isIn(in));


	}

void testIsInEmpty() {

	//tests if a value is found if the set is empty

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);

        int in = 40;

        bool expected = false;

        ASSERT_EQUAL(expected,listObj2.isIn(in));


	}

void testAdd1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int notadd = 3;


        string expectedObj2 = "1, 2, 3, 7, 8";
        int expectedObj2Size = 5;

        listObj2.add(notadd);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testAdd2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int addmiddle = 4;


        string expectedObj2 = "1, 2, 3, 4, 7, 8";
        int expectedObj2Size = 6;

        listObj2.add(addmiddle);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}


void testAdd3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int addlast = 9;


        string expectedObj2 = "1, 2, 3, 7, 8, 9";
        int expectedObj2Size = 6;

        listObj2.add(addlast);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int addfirst = 0;  // test add

        string expectedObj2 = "0, 1, 2, 3, 7, 8";
        int expectedObj2Size = 6;

        listObj2.add(addfirst);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd5() {

	//tests when the set is positive and a negative value is to be added to the set

    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);


        int addnegative = -15;  // test add

        string expectedObj2 = "-15, 10, 20, 30, 40";
        int expectedObj2Size = 5;

        listObj2.add(addnegative);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd6() {

	//tests when the set is positive and a fraction is to be added to the set

    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);


        int addfraction = 50/2;  // test add

        string expectedObj2 = "10, 20, 25, 30, 40";
        int expectedObj2Size = 5;

        listObj2.add(addfraction);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd7() {

	//tests when both sets are negative and the a negative fraction is to be added to the set

    int arr[] = {-40, -30, -25, -20}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);


        int addnegative = -20/2;  // test add

        string expectedObj2 = "-40, -30, -25, -20, -10";
        int expectedObj2Size = 5;

        listObj2.add(addnegative);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}


void testRemove1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int notremove = 10;

        //test remove

        listObj2.remove(notremove);

        string expectedObj2 = "1, 2, 3, 7, 8";
        int expectedObj2Size = 5;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());




	}


void testRemove2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int removemiddle = 3;


        //test remove

        listObj2.remove(removemiddle);

        string expectedObj2 = "1, 2, 7, 8";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testRemove3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int removelast = 8;


        //test remove

        listObj2.remove(removelast);

        string expectedObj2 = "1, 2, 3, 7";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int removefirst = 1;  // test remove

        //test remove

        listObj2.remove(removefirst);

        string expectedObj2 = "2, 3, 7, 8";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove5() {

	//remove a fraction value that is equivalent to a value in the set

    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);

        int removefraction = 40/2;  // test remove

        //test remove

        listObj2.remove(removefraction);

        string expectedObj2 = "10, 30, 40";
        int expectedObj2Size = 3;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove6() {

	//remove a negative value in the middle

    int arr[] = {-30, -20, -15, -10}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);

        int removenegative = -15;  // test remove

        //test remove

        listObj2.remove(removenegative);

        string expectedObj2 = "-30, -20, -10";
        int expectedObj2Size = 3;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove7() {

	//remove a value when the set is empty
	//not possible

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);

        int removeempty = 7;  // test remove

        //test remove

        listObj2.remove(removeempty);

        string expectedObj2 = "";
        int expectedObj2Size = 0;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}


void testUnion1() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);




        SLLSet listObj3 = SLLSet();
        SLLSet listObj4 = listObj2.setUnion(listObj3);


        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj4.getSize());
        ASSERT_EQUAL(expected,listObj4.toString());




	}


void testUnion2() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
    int uni1[] = {0, 2, 3, 8, 10, 20};


        SLLSet listObj5 = SLLSet(uni1,6);
        SLLSet listObj6 = listObj2.setUnion(listObj5);

        string expected = "0, 1, 2, 3, 7, 8, 10, 20";
        int expectedSize = 8;

        ASSERT_EQUAL(expectedSize,listObj6.getSize());
        ASSERT_EQUAL(expected,listObj6.toString());



	}

void testUnion3() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
        int uni2[] = {0, 2, 3}; // for testing union
        SLLSet listObj7 = SLLSet(uni2,3);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "0, 1, 2, 3, 7, 8";
        int expectedSize = 6;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}

void testUnion4() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        SLLSet listObj3 = SLLSet();
        SLLSet listObj9 = listObj3.setUnion(listObj2);

        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj9.getSize());
        ASSERT_EQUAL(expected,listObj9.toString());


	}

void testUnion5() {

	//tests when the last value in the second set is the only and last value from that set being added to the union set
        // test union
    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);
        int uni3[] = {30, 40, 50}; // for testing union
        SLLSet listObj7 = SLLSet(uni3,3);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "10, 20, 30, 40, 50";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}

void testUnion6() {

	//tests when both sets are negative and a union set can be produced

        // test union
    int arr[] = {-40, -30, -20, -10}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);
        int uni4[] = {-35, -32, -25,-10}; // for testing union
        SLLSet listObj7 = SLLSet(uni4,4);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "-40, -35, -32, -30, -25, -20, -10";
        int expectedSize = 7;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}

void testUnion7() {

	//tests when there are fractions present in one of the sets

        // test union
    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);
        int uni5[] = {15, 20, 50/2, 70/2}; // for testing union
        SLLSet listObj7 = SLLSet(uni5,4);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "10, 15, 20, 25, 30, 35, 40";
        int expectedSize = 7;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}

void testUnion8() {

	//tests when both sets are empty

        // test union
    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);




        SLLSet listObj3 = SLLSet();
        SLLSet listObj4 = listObj2.setUnion(listObj3);


        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj4.getSize());
        ASSERT_EQUAL(expected,listObj4.toString());




	}

void testUnion9() {

	//test when both sets are the same

        // test union
    int arr[] = {10, 20, 30, 40}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);
        int uni5[] = {10, 20, 30 , 40}; // for testing union
        SLLSet listObj7 = SLLSet(uni5,4);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "10, 20, 30, 40";
        int expectedSize = 4;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}





void testIntersection1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        SLLSet listObj9 = SLLSet();
        SLLSet listObj10 = listObj2.intersection(listObj9);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj10.getSize());
        ASSERT_EQUAL(expected,listObj10.toString());



	}

void testIntersection2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

    int arr2[] = {0,2,7}; // this list
    SLLSet listObj11 =  SLLSet(arr2,3);


        SLLSet listObj12 = listObj2.intersection(listObj11);

        string expected = "2, 7";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj12.getSize());
        ASSERT_EQUAL(expected,listObj12.toString());




	}

void testIntersection3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int inter2[] = {1, 3, 5, 6, 8, 10};




        SLLSet listObj13 = SLLSet(inter2,6);
        SLLSet listObj14 = listObj2.intersection(listObj13);

        string expected = "1, 3, 8";
        int expectedSize = 3;

        ASSERT_EQUAL(expectedSize,listObj14.getSize());
        ASSERT_EQUAL(expected,listObj14.toString());






	}

void testIntersection4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


    int inter3[] = {0, 10, 100}; //test intersection

    SLLSet listObj15 = SLLSet(inter3,3);
    SLLSet listObj16 = listObj2.intersection(listObj15);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj16.getSize());
        ASSERT_EQUAL(expected,listObj16.toString());

	}

void testIntersection5() {

	//tests when both sets are empty

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);


        SLLSet listObj9 = SLLSet();
        SLLSet listObj10 = listObj2.intersection(listObj9);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj10.getSize());
        ASSERT_EQUAL(expected,listObj10.toString());



	}

void testIntersection6() {

	//tests when both sets are positive but the values in the set are fractions at the first and last node
	//both fractions in the second set match the first and last fractions in the first set

    int arr[] = {10, 20, 30, 40, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int inter4[] = {20/2, 25, 31, 35, 41, 100/2};




        SLLSet listObj13 = SLLSet(inter4,6);
        SLLSet listObj14 = listObj2.intersection(listObj13);

        string expected = "10, 50";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj14.getSize());
        ASSERT_EQUAL(expected,listObj14.toString());






	}

void testIntersection7() {

	//test when both sets are negative and there are fractions present in the set

    int arr[] = {-50, -40, -30, -20, -10}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int inter5[] = {-55, -47, -180/6, -20, -5};




        SLLSet listObj13 = SLLSet(inter5,5);
        SLLSet listObj14 = listObj2.intersection(listObj13);

        string expected = "-30, -20";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj14.getSize());
        ASSERT_EQUAL(expected,listObj14.toString());






	}

void testIntersection8() {

	//tests when both sets are negative and no intersections are present between the two sets

    int arr[] = {-50, -40, -30, -20, -10}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int inter6[] = {-55, -47, -42, -27, -5, 0};




        SLLSet listObj13 = SLLSet(inter6,6);
        SLLSet listObj14 = listObj2.intersection(listObj13);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj14.getSize());
        ASSERT_EQUAL(expected,listObj14.toString());






	}

void testIntersection9() {

	//tests when both sets have the same elements

    int arr[] = {10, 20, 30, 40, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

    int arr7[] = {10, 20, 30, 40, 50}; // this list


        SLLSet listObj11 =  SLLSet(arr7,5);
        SLLSet listObj12 = listObj2.intersection(listObj11);

        string expected = "10, 20, 30, 40, 50";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj12.getSize());
        ASSERT_EQUAL(expected,listObj12.toString());




	}




void testDifference1() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        SLLSet listObj17 = SLLSet();
        SLLSet listObj18 = listObj2.difference(listObj17);

        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj18.getSize());
        ASSERT_EQUAL(expected,listObj18.toString());


	}

void testDifference2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);



        int diff1[] = {1, 2, 3, 5, 7, 8, 9};
        SLLSet listObj19 = SLLSet(diff1,7);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}


void testDifference3() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);




    int diff2[] = {1, 2, 3}; // test difference
    // test difference
    SLLSet listObj21 = SLLSet(diff2,3);
    SLLSet listObj22 = listObj2.difference(listObj21);

        string expected = "7, 8";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj22.getSize());
        ASSERT_EQUAL(expected,listObj22.toString());





	}


void testDifference4() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
        SLLSet listObj17 = SLLSet();
        SLLSet listObj1000 = listObj17.difference(listObj2);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj1000.getSize());
        ASSERT_EQUAL(expected,listObj1000.toString());

	}

void testDifference5() {

	//tests if there is a difference when both sets are empty

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);

        SLLSet listObj17 = SLLSet();
        SLLSet listObj18 = listObj2.difference(listObj17);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj18.getSize());
        ASSERT_EQUAL(expected,listObj18.toString());


	}

void testDifference6() {

	//tests when the second set is fully different from the first set

    int arr[] = {10, 20, 30, 40, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);



        int diff3[] = {0, 1, 2, 3, 4, 5, 17};
        SLLSet listObj19 = SLLSet(diff3,7);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "10, 20, 30, 40, 50";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}

void testDifference7() {

	//tests when both the sets are negative

    int arr[] = {-30, -20, -10, -5}; // this list
    SLLSet listObj2 =  SLLSet(arr,4);



        int diff4[] = {-40, -30, -20, -7};
        SLLSet listObj19 = SLLSet(diff4,4);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "-10, -5";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}

void testDifference8() {

	//tests when both the sets are negative

    int arr[] = {10, 60/3, 30, 80/2, 50}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);



        int diff5[] = {10, 15, 37, 40};
        SLLSet listObj19 = SLLSet(diff5,4);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "20, 30, 50";
        int expectedSize = 3;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}

void testDifference9() {

	//tests when both the sets are empty

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);



        int diff6[] = {};
        SLLSet listObj19 = SLLSet(diff6,0);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}

void testUnionSLLSetArray() {

        int arr1[] = {0, 1, 2};
        int arr2[] = {1, 2, 3, 4};
        int arr3[] = {0, 1};
        int arr4[] = {6, 7};
        SLLSet listObj100 = SLLSet(arr1,3);
        SLLSet listObj99 = SLLSet(arr2,4);
        SLLSet listObj98 = SLLSet(arr3,2);
        SLLSet listObj97 = SLLSet(arr4,2);
        SLLSet listObj96 = SLLSet();
        SLLSet Array[] = {listObj100, listObj99, listObj98, listObj97, listObj96}; // test static SLLSet union(sArray)

		 SLLSet listObj23 = SLLSet::setUnion(Array,5);

		 string expected = "0, 1, 2, 3, 4, 6, 7";
		 int expectedSize = 7;

		 ASSERT_EQUAL(expectedSize,listObj23.getSize());
		 ASSERT_EQUAL(expected,listObj23.toString());


	}

void testUnionSLLSetArray_Empty() {

	    //tests when all the sets are empty

        int arr1[] = {};
        int arr2[] = {};
        int arr3[] = {};
        int arr4[] = {};
        SLLSet listObj100 = SLLSet(arr1,0);
        SLLSet listObj99 = SLLSet(arr2,0);
        SLLSet listObj98 = SLLSet(arr3,0);
        SLLSet listObj97 = SLLSet(arr4,0);
        SLLSet listObj96 = SLLSet();
        SLLSet Array[] = {listObj100, listObj99, listObj98, listObj97, listObj96}; // test static SLLSet union(sArray)

		 SLLSet listObj23 = SLLSet::setUnion(Array,5);

		 string expected = "";
		 int expectedSize = 0;

		 ASSERT_EQUAL(expectedSize,listObj23.getSize());
		 ASSERT_EQUAL(expected,listObj23.toString());


	}

void testUnionSLLSetArray_Mix() {

	    //tests when there is a mix of negative, positive, and fractional values in the sets

        int arr1[] = {-5, -3, -6/3, 0};
        int arr2[] = {10, 20, 30};
        int arr3[] = {36, 75};
        int arr4[] = {-15, 27/3, 45};
        SLLSet listObj100 = SLLSet(arr1,4);
        SLLSet listObj99 = SLLSet(arr2,3);
        SLLSet listObj98 = SLLSet(arr3,2);
        SLLSet listObj97 = SLLSet(arr4,3);
        SLLSet Array[] = {listObj100, listObj99, listObj98, listObj97}; // test static SLLSet union(sArray)

		 SLLSet listObj23 = SLLSet::setUnion(Array,4);

		 string expected = "-15, -5, -3, -2, 0, 9, 10, 20, 30, 36, 45, 75";
		 int expectedSize = 12;

		 ASSERT_EQUAL(expectedSize,listObj23.getSize());
		 ASSERT_EQUAL(expected,listObj23.toString());


	}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };


	//TODO add your test here

    s.push_back(CUTE(testSLLSet));
    s.push_back(CUTE(testSLLSetIntArray));
    s.push_back(CUTE(testSLLSetIntArray_Empty));
    s.push_back(CUTE(testCopy));
    s.push_back(CUTE(testCopy2));
    s.push_back(CUTE(testCopy3));
    s.push_back(CUTE(testIsInTrue));
    s.push_back(CUTE(testIsInFalse));
    s.push_back(CUTE(testIsInFraction));
    s.push_back(CUTE(testIsInNegative));
    s.push_back(CUTE(testIsInEmpty));
    s.push_back(CUTE( testAdd1));
    s.push_back(CUTE(testAdd2));
    s.push_back(CUTE(testAdd3));
    s.push_back(CUTE(testAdd4));
    s.push_back(CUTE(testAdd5));
    s.push_back(CUTE(testAdd6));
    s.push_back(CUTE(testAdd7));
    s.push_back(CUTE(testRemove1));
    s.push_back(CUTE(testRemove2));
    s.push_back(CUTE(testRemove3));
    s.push_back(CUTE(testRemove4));
    s.push_back(CUTE(testRemove5));
    s.push_back(CUTE(testRemove6));
    s.push_back(CUTE(testRemove7));
    s.push_back(CUTE(testUnion1));
    s.push_back(CUTE(testUnion2));
    s.push_back(CUTE(testUnion3));
    s.push_back(CUTE(testUnion4));
    s.push_back(CUTE(testUnion5));
    s.push_back(CUTE(testUnion6));
    s.push_back(CUTE(testUnion7));
    s.push_back(CUTE(testUnion8));
    s.push_back(CUTE(testUnion9));
    s.push_back(CUTE(testIntersection1));
    s.push_back(CUTE(testIntersection2));
    s.push_back(CUTE(testIntersection3));
    s.push_back(CUTE(testIntersection4));
    s.push_back(CUTE(testIntersection5));
    s.push_back(CUTE(testIntersection6));
    s.push_back(CUTE(testIntersection7));
    s.push_back(CUTE(testIntersection8));
    s.push_back(CUTE(testIntersection9));
    s.push_back(CUTE(testDifference1));
    s.push_back(CUTE(testDifference2));
    s.push_back(CUTE(testDifference3));
    s.push_back(CUTE(testDifference4));
    s.push_back(CUTE(testDifference5));
    s.push_back(CUTE(testDifference6));
    s.push_back(CUTE(testDifference7));
    s.push_back(CUTE(testDifference8));
    s.push_back(CUTE(testDifference9));
    s.push_back(CUTE(testUnionSLLSetArray));
    s.push_back(CUTE(testUnionSLLSetArray_Empty));
    s.push_back(CUTE(testUnionSLLSetArray_Mix));





	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
