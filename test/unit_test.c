#include "unity.h"
#include "init_game.h"
#include <stdlib.h>
#include <stdio.h>

void test_dead_cell_with_0_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT(expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_1_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_2_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_3_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {1,1,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_4_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[1][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,1,0}, {1,0,1}, {0,1,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_5_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[0][0] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,1,0}, {1,0,1}, {0,1,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_6_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[0][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {1,0,1}, {0,1,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_7_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[2][0] = 1;
    	theBoard->cell[0][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {0,0,1}, {1,1,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_dead_cell_with_8_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[0][2] = 1;
    	theBoard->cell[2][0] = 1;
    	theBoard->cell[2][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {0,0,0}, {1,0,1}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_live_cell_with_0_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_live_cell_with_1_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{0,0,0}, {0,0,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}

void test_live_cell_with_2_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,1,0}, {1,1,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_3_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,1,0}, {1,1,0}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_4_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[0][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {1,0,1}, {0,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_5_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[0][2] = 1;
    	theBoard->cell[1][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {1,0,1}, {0,1,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_6_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[0][2] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[2][0] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {0,0,1}, {1,0,0}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_7_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[0][2] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[2][0] = 1;
    	theBoard->cell[2][1] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {0,0,0}, {1,0,1}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void test_live_cell_with_8_live_neighbor() {
	Board *theBoard = (Board *) malloc(sizeof(Board));
	theBoard->row = 3;
	theBoard->col = 3;
	InitialCell(theBoard,theBoard->row,theBoard->col);
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            theBoard->cell[i][j] = 0;
        }      
    }
    	theBoard->cell[1][1] = 1;
    	theBoard->cell[0][1] = 1;
    	theBoard->cell[0][0] = 1;
    	theBoard->cell[1][0] = 1;
    	theBoard->cell[0][2] = 1;
    	theBoard->cell[1][2] = 1;
    	theBoard->cell[2][0] = 1;
    	theBoard->cell[2][1] = 1;
    	theBoard->cell[2][2] = 1;
    	UpdateCell(theBoard);
	const int** expCell[3][3]={{1,0,1}, {0,0,0}, {1,0,1}};
	for(int i=0;i<(theBoard->row);i++)
    {
        for(int j=0;j<(theBoard->col);j++){
            TEST_ASSERT_EQUAL_INT (expCell[i][j],theBoard->cell[i][j]);
        }   
      }   
	FreeCell(theBoard);
}


void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_dead_cell_with_0_live_neighbor);
	RUN_TEST(test_dead_cell_with_1_live_neighbor);
	RUN_TEST(test_dead_cell_with_2_live_neighbor);
	RUN_TEST(test_dead_cell_with_3_live_neighbor);
	RUN_TEST(test_dead_cell_with_4_live_neighbor);
	RUN_TEST(test_dead_cell_with_5_live_neighbor);
	RUN_TEST(test_dead_cell_with_6_live_neighbor);
	RUN_TEST(test_dead_cell_with_7_live_neighbor);
	RUN_TEST(test_dead_cell_with_8_live_neighbor);
	RUN_TEST(test_live_cell_with_0_live_neighbor);
	RUN_TEST(test_live_cell_with_1_live_neighbor);
	RUN_TEST(test_live_cell_with_2_live_neighbor);
	RUN_TEST(test_live_cell_with_3_live_neighbor);
	RUN_TEST(test_live_cell_with_4_live_neighbor);
	RUN_TEST(test_live_cell_with_5_live_neighbor);
	RUN_TEST(test_live_cell_with_6_live_neighbor);
	RUN_TEST(test_live_cell_with_7_live_neighbor);
	RUN_TEST(test_live_cell_with_8_live_neighbor);
	return UNITY_END();
}
