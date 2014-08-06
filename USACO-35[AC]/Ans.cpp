#include <stdio.h>
#include <stdlib.h>

int r, c;
FILE *fout;

struct piece_f {
    int serial;
    char edge[8];	/* twice for efficiency */
			/* top, right, bottom, left */
    int rotation;	/* 0..4 depending on rotation */
    int used;
} piece[800];
int npieces;

int puzzle[25][25];

	/* rotated edge */
#define ROTEDGE(p,dir)  piece[p].edge[piece[p].rotation+dir]

void place (int row,int col) {	/* place every available piece at row,col in four rotations */
    int i, j;

    if (col == c) {	/* did we fill this column? */
	row++;
	col = 0;	/* onto first piece of next row */
	if (row == r) {	/* solution! print answer */
	    for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
		    int k = puzzle[i][j];
		    fprintf (fout, "%d %c %c %c %c\n", piece[k].serial,
			ROTEDGE(k,0), ROTEDGE(k,1), ROTEDGE(k,2),
			ROTEDGE(k,3));
		}
	    }
	    exit (0);
	}
    }
	/* place the properly rotated piece */
    for (i = 0; i < npieces; i++) {	/* all pieces */
	int mytop, myright, mybot, myleft;
	if (piece[i].used) continue;	/* already placed */
	piece[i].used = 1;		/* mark as placed */
	puzzle[row][col] = i;		/* insert the piece */
	for (j = 0; j < 4; j++) {	/* in all possible rotations */
	    piece[i].rotation = j;	/* set rotation */
	    mytop = ROTEDGE(i,0);	/* bad placement? try another rotation */
	    if (row == 0   && mytop != '0') continue;  /* top border */
	    myright = ROTEDGE(i,1);
	    if (col == c-1 && myright != '0') continue;  /* right border */
	    mybot = ROTEDGE(i,2);
	    if (row == r-1 && mybot != '0') continue;  /* bot border */
	    myleft = ROTEDGE(i,3);
	    if (col == 0   && myleft != '0') continue;  /* left border */
		/* match top */
	    if (row > 0 && mytop != ROTEDGE(puzzle[row-1][col],2))   continue;
	    if (col > 0 && myleft != ROTEDGE(puzzle[row][col-1],1))  continue;
		/* this piece is finally placed legally, try the next one */
	    place (row, col+1);
		/* ok, back from all possible subsequent pieces; try this one
	           again, and return when all pieces and rotations have been tried */
	}
	piece[i].used = 0;
    }
}

main () {
    int i, j, k, serial;
    FILE *fin = fopen ("jigsaw.in", "r");
    fout = fopen ("jigsaw.out", "w");
    fscanf (fin, "%d %d", &r, &c);
    for (npieces = 0; npieces < r*c; npieces++) {
	fscanf (fin, "%d", &piece[npieces].serial);
	piece[npieces].used = 0;
	for (i = 0; i < 4; i++) {
	    char in[5];		/* bigger than we need */
	    fscanf (fin, "%s", in);
				/* place edge twice to enable easy rotation */
	    piece[npieces].edge[i] = piece[npieces].edge[i+4] = in[0];
	}
    }
    place (0, 0);		/* start recursion in upper left corner */
    fprintf (fout, "impossible\n");
    exit (0);
}
