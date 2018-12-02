//Name= Elham Hojati
//Lab501 or Lab503 

#include "project2.h"



//_________________________________________________________________________

//function definition:

position readPosition(string s)
{

	row r1(8, "e");
	position p1(8, r1);



	int a, b;
	string c;

	// loop
	for (int i = 0; i < (signed)s.size(); ++i)
	{


		// if vector has something inside of it
		if (s[i] != ' ')
		{
			// a - row
			a = int(s[i + 2]) - int('0') - 1;

			// b - column
			b = int(s[i + 3]) - int('a');

			// c - name of the figure
			c = s.substr(i, 2);

			// position
			p1[a][b] = c;

			i = i + 3;
		}

	}

	return p1;
}

//_________________________________________________________________________


// RESTRICTIONS ON THE FIELD

// check statement for knights
// check return 
bool check(position P, color c)
{

	// start looking for the whole board

	char colorKing;
	char oppositeColor;
	bool result = false;


	for (int i = 0; i < 7; i++)			// по горизонтали
	{
		for (int j = 0; j < 7; ++j)		// по вертикали
		{
			// find a KING and start work with it
			if (pieceType(i, j, P) == "K")
			{

				// fining the colors
				colorKing = pieceColor(i, j, P);

				if (colorKing == 'W')
					oppositeColor = 'B';
				else
					oppositeColor = 'W';



				//------------------------------------------------------------------------
				// LOOKING UP FROM POSITION OF THE KING
				{	int t = i + 1;	// index -> rank

									// while rank is not out of the board
									// & its not occupied by the piece of the same color
									// & not occupied by the piece of opposite color 
				while (t <= 7 && !(occupied(t, j, P, colorKing)) && !(occupied(t, j, P, oppositeColor)))
				{
					t = t + 1;	// keep going up
				}
				if (t <= 7) {

					if (occupied(t, j, P, oppositeColor) && (pieceType(t, j, P) == "r" || pieceType(t, j, P) == "Q"))
					{
						result = true;
					}
				}
				}

				//------------------------------------------------------------------------

				// LOOKING DOWN FROM POSITION OF THE KING
				{int t = i - 1;
				while (t >= 0 && !(occupied(t, j, P, colorKing)) && !(occupied(t, j, P, oppositeColor)))
				{
					t = t - 1;
				}
				if (t >= 0) {

					if (occupied(t, j, P, oppositeColor) && (pieceType(t, j, P) == "r" || pieceType(t, j, P) == "Q"))
					{
						result = true;

					}
				}
				}

				//------------------------------------------------------------------------

				// LOOKING LEFT FROM POSITION OF THE KING
				{	int t = j - 1;
				while (t >= 0 && !(occupied(i, t, P, colorKing)) && !(occupied(i, t, P, oppositeColor)))
				{
					t = t - 1;
				}
				if (t >= 0) {

					if (occupied(t, j, P, oppositeColor) && (pieceType(t, j, P) == "r" || pieceType(t, j, P) == "Q"))
					{
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING RIGHT FROM POSITION OF THE KING
				{ int t = j + 1;
				while (t <= 7 && !(occupied(t, j, P, colorKing)) && !(occupied(t, j, P, oppositeColor)))
				{
					t = t + 1;
				}
				if (t <= 7) {

					if (occupied(t, j, P, oppositeColor) && (pieceType(t, j, P) == "r" || pieceType(t, j, P) == "Q"))
					{
						result = true;

					}
				}}




				//------------------------------------------------------------------------
				// LOOKING UP & LEFT FROM POSITION OF THE KING
				{int t = i + 1;
				int k = j - 1;
				while (((k >= 0) && (t <= 7)) && !(occupied(t, k, P, colorKing)) && !(occupied(t, k, P, oppositeColor)))
				{
					t = t + 1;
					k = k - 1;
				}
				// if file > 0, and rank < 7
				if ((k >= 0) && (t <= 7)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "b" || pieceType(t, k, P) == "Q" ))
					{
						//	if (king is white) and pawn is black
						// if the king is blak and pawn is white
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING UP & RIGHT FROM POSITION OF THE KING
				{int t = i + 1;
				int k = j + 1;
				while (((k <= 7) && (t <= 7)) && !(occupied(t, k, P, colorKing)) && !(occupied(t, k, P, oppositeColor)))
				{
					t = t + 1;
					k = k + 1;
				}
				// if file > 0, and rank < 7
				if ((k <= 7) && (t <= 7)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "b" || pieceType(t, k, P) == "Q"))
					{
						result = true;

					}
				}}

				//------------------------------------------------------------------------

				// LOOKING DOWN & LEFT FROM POSITION OF THE KING
				{int t = i - 1;
				int k = j - 1;
				while (((k >= 0) && (t >= 0)) && !(occupied(t, k, P, colorKing)) && !(occupied(t, k, P, oppositeColor)))
				{
					t = t - 1;
					k = k - 1;
				}
				// if file > 0, and rank < 7
				if ((k >= 0) && (t >= 0)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "b" || pieceType(t, k, P) == "Q"))
					{
						result = true;
					}
				}}

				//------------------------------------------------------------------------

				// LOOKING DOWN & RIGHT FROM POSITION OF THE KING
				{int t = i - 1;
				int k = j + 1;
				while (((k <= 7) && (t >= 0)) && !(occupied(t, k, P, colorKing)) && !(occupied(t, k, P, oppositeColor)))
				{
					t = t - 1;
					k = k + 1;
				}
				// ?????????????????????????????????????
				// if ((k >= 0) && (t >= 0)) {
				if ((k <= 7) && (t >= 0)) {

					// if there is a BISHOP or QUEEN 
					if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "b" || pieceType(t, k, P) == "Q"))
					{
						result = true;
					}
				}
				}



				// PAWNS
				//------------------------------------------------------------------------

				// PAWN look UP & LEFT (BLACK PAWNS)
				{
					if (colorKing == 'W')
					{
						int t = i + 1;		// rank
						int k = j - 1;		// file

						if ((k >= 0) && (t <= 7)) {
							// if there is a BLACK PAWN
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "p"))
							{
								result = true;

							}
						}
					}
				}

				// PAWN look UP & RIGHT (BLACK PAWNS)
				{
					if (colorKing == 'W')
					{
						int t = i + 1;		// rank
						int k = j + 1;		// file

						if ((k <= 7) && (t <= 7)) {
							// if there is a BLACK PAWN
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "p"))
							{
								result = true;

							}
						}
					}
				}


				// PAWN look DOWN & LEFT (WHITE PAWNS)
				{
					if (colorKing == 'B')
					{
						int t = i - 1;		// rank
						int k = j - 1;		// file

						if ((k >= 0) && (t >= 0)) {
							// if there is a WHITE PAWN
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "p"))
							{
								result = true;

							}
						}
					}
				}

				// PAWN look DOWN & RIGHT (WHITE PAWNS)
				{
					if (colorKing == 'B')
					{
						int t = i - 1;		// rank
						int k = j + 1;		// file

						if ((k <= 7) && (t >= 0)) {
							// if there is a BLACK PAWN
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "p"))
							{
								result = true;

							}
						}
					}
				}



				// KNIGHTS
				//------------------------------------------------------------------------

				// 2 UP & RIGHT
				{

						int t = i + 2;		// rank
						int k = j + 1;		// file

						if ((k <= 7) && (t <= 7)) {
							// if there is a KNIGHT
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "k"))
							{
								result = true;

							}
						}

				}

				// 2 UP & LEFT
				{
					if (colorKing == 'W')
					{
						int t = i + 2;		// rank
						int k = j - 1;		// file

						if ((k >= 0) && (t <= 7)) {
							// if there is a KNIGHT
							if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "k"))
							{
								result = true;

							}
						}
					}
				}
			
				// 2 DOWN & RIGHT
				{

					int t = i - 2;		// rank
					int k = j + 1;		// file

					if ((k <= 7) && (t >= 0)) {
						// if there is a KNIGHT
						if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "k"))
						{
							result = true;

						}
					}

				}

				// 2 DOWN & LEFT
				{

					int t = i - 2;		// rank
					int k = j - 1;		// file

					if ((k >= 0) && (t >= 0)) {
						// if there is a KNIGHT
						if (occupied(t, k, P, oppositeColor) && (pieceType(t, k, P) == "k"))
						{
							result = true;

						}
					}

				}

			}
		}
	}



	return result; // ???????????

}


//ready
bool checkmate(position P, color c)
{

	position Res, R;
	set<mov> moves = simpMoves(P, c);	// all simple moves



	if (!(check(P, c)))
	{
		return false;
	}

	// all elements of set simpMoves
	for (std::set<mov>::iterator it = moves.begin(); it != moves.end(); ++it)	// goes through all possible moves
	{
		R = result(P, (mov)*it);		// shows all possible moves

		if (!(check(R, c)))
			return false;
	}
	return true;

	

}

position result(position P, mov m)
{

	int c1, d1, c2, d2;
	position P2 = P;
	string k;

	string a = m.src;		// for ex "3c"
	string b = m.dst;		// for ex "4c"


	// for initial conditions
	c1 = int(a[0]) - int('0') - 1;		// rank		
	d1 = int(a[1]) - int('a');			// file	


    // for final move
	c2 = int(b[0]) - int('0') - 1;		// rank		
	d2 = int(b[1]) - int('a');			// file	


	
			k = P2[c1][d1];  // for ex k = "WK"


			P2[c1][d1] = "e";	// empty 

			P2[c2][d2] = k; // update new position


			return P2;
}

bool stalemate(position P, color c)
{
	// there is a stalemate in position p on c's move if
	// c is not in check AND
	// c is in check in every simplified successor of p

//	if (c != check(P, c))

	position Res, R;
	set<mov> moves = simpMoves(P, c);	// all simple moves
	bool st = false;


	if (check(P, c))
		return false;


	for (std::set<mov>::iterator it = moves.begin(); it != moves.end(); ++it)
	{
		R = result(P, (mov)*it);

		if (!(check(R, c)))
			return false;
	}

	return true;
}

bool occupied(Rank r, file f, position P, color c) 
{
	// 	string s; //(if problem)

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)


	if (P[a][b][0] == c)				// if some color on the cell
	{
		return true;					// it is occupied
	}
	else
		return false;

	// s = P[a][b]
	// s.substr(1,0) == c;


}

/*bool occupied(Rank r, file f, position P, color c)
{
	 	string s; //(if problem)

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)


	s = P[a][b];
	s.substr(1,0) = c;

	if (c)				// if some color on the cell
	{
		return true;					// it is occupied
	}
	else
		return false;


}*/



// LEGAL MOVES FOR EACH PIECE 

set<mov> legalMovesKing(Rank r, file f, position P)	// no check, no stalemate 
{

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorKing;
	char oppositeColor;

	colorKing = pieceColor(a, b, P);

	if (colorKing == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';

	set<mov> Res;
	mov m;


	// up
	{
		// if not occupied
		if (!occupied(a + 1, b, P, oppositeColor) && !(occupied(a + 1, b, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a + 1;
			m.dst = b;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a + 1, b, P, oppositeColor) && !(pieceType(a + 1, b, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a + 1;
			m.dst = b;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a + 1, b, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// down
	{
		// if not occupied
		if (!occupied(a - 1, b, P, oppositeColor) && !(occupied(a - 1, b, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a - 1;
			m.dst = b;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a - 1, b, P, oppositeColor) && !(pieceType(a - 1, b, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a - 1;
			m.dst = b;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a - 1, b, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// right
	{
		// if not occupied
		if (!occupied(a, b + 1, P, oppositeColor) && !(occupied(a, b + 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a, b + 1, P, oppositeColor) && !(pieceType(a, b + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a, b + 1, P, colorKing))
		{
			
		}
	}

	// left
	{
		// if not occupied
		if (!occupied(a, b - 1, P, oppositeColor) && !(occupied(a, b - 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a, b - 1, P, oppositeColor) && !(pieceType(a, b - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a, b - 1, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// up & right
	{
		// if not occupied
		if (!occupied(a + 1, b + 1, P, oppositeColor) && !(occupied(a + 1, b + 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a + 1;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a + 1, b + 1, P, oppositeColor) && !(pieceType(a + 1, b + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a + 1;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a + 1, b + 1, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// up & left
	{
		// if not occupied
		if (!occupied(a + 1, b - 1, P, oppositeColor) && !(occupied(a + 1, b - 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a + 1;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a + 1, b - 1, P, oppositeColor) && !(pieceType(a + 1, b - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a + 1;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a + 1, b - 1, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// down & left
	{
		// if not occupied
		if (!occupied(a - 1, b - 1, P, oppositeColor) && !(occupied(a - 1, b - 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a - 1;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a - 1, b - 1, P, oppositeColor) && !(pieceType(a - 1, b - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a - 1;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a - 1, b - 1, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// down & right
	{
		// if not occupied
		if (!occupied(a - 1, b + 1, P, oppositeColor) && !(occupied(a - 1, b + 1, P, colorKing)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a - 1;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a - 1, b + 1, P, oppositeColor) && !(pieceType(a - 1, b + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a - 1;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a - 1, b + 1, P, colorKing))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	return Res;
}

// (check statement for case when occupied by the same color)
set<mov> legalMovesKnight(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorKnight;
	char oppositeColor;

	colorKnight = pieceColor(a, b, P);

	if (colorKnight == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;

	// 2 up & right
	{
		// if not occupied
		if (!occupied(a + 2, b + 1, P, oppositeColor) && !(occupied(a + 2, b + 1, P, colorKnight)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a + 2;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a + 2, b + 1, P, oppositeColor) && !(pieceType(a + 2, b + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a + 2;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a + 2, b + 1, P, colorKnight))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// 2 down & left
	{
		// if not occupied
		if (!occupied(a - 2, b - 1, P, oppositeColor) && !(occupied(a - 2, b - 1, P, colorKnight)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a - 2;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a - 2, b - 1, P, oppositeColor) && !(pieceType(a - 2, b - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a - 2;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a - 2, b - 1, P, colorKnight))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// 2 down & right
	{
		// if not occupied
		if (!occupied(a - 2, b + 1, P, oppositeColor) && !(occupied(a - 2, b + 1, P, colorKnight)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a - 2;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a - 2, b + 1, P, oppositeColor) && !(pieceType(a - 2, b + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a - 2;
			m.dst = b + 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a - 2, b + 1, P, colorKnight))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	// 2 up & left
	{
		// if not occupied
		if (!occupied(a + 2, b - 1, P, oppositeColor) && !(occupied(a + 2, b - 1, P, colorKnight)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a + 2;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by opposite color
		else if (occupied(a + 2, b - 1, P, oppositeColor) && !(pieceType(a + 2, b - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a + 2;
			m.dst = b - 1;
			Res.insert(m);
		}
		// if occupied by the same color
		else if (occupied(a + 2, b - 1, P, colorKnight))
		{
			m.src = a;
			m.dst = b;
			Res.insert(m);
		}
	}

	return Res;
}

set<mov> legalMovesRook(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorRook;
	char oppositeColor;

	colorRook = pieceColor(a, b, P);

	if (colorRook == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;

	// right
	for (int i = b - 1; i <= 7; ++i) {	// a -1 index
		if (!occupied(a, i + 1, P, oppositeColor) && !(occupied(a, i + 1, P, colorRook)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a;
			m.dst = i + 1;
			Res.insert(m);
		}
		else if (occupied(a, i + 1, P, oppositeColor) && !(pieceType(a, i + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a;
			m.dst = i + 1;
			Res.insert(m);
		}
		else if (occupied(a, i + 1, P, colorRook))
		{
			break;
		}
	}

	// forward
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		if (!occupied(i + 1, b, P, oppositeColor) && !(occupied(i + 1, b, P, colorRook)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = i + 1;
			m.dst = b;
			Res.insert(m);
		}
		else if (occupied(i + 1, b, P, oppositeColor) && !(pieceType(i + 1, b, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = i + 1;
			m.dst = b;
			Res.insert(m);
		}
		else if (occupied(i + 1, b, P, colorRook))
		{
			break;
		}
	}

	// left
	for (int i = b - 1; i <= 7; ++i) {	// a -1 index
		if (!occupied(a, i - 1, P, oppositeColor) && !(occupied(a, i - 1, P, colorRook)) &&!(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = a;
			m.dst = i - 1;
			Res.insert(m);
		}
		else if (occupied(a, i - 1, P, oppositeColor) && !(pieceType(a, i - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = a;
			m.dst = i - 1;
			Res.insert(m);
		}
		else if (occupied(a, i - 1, P, colorRook))
		{
			break;
		}
	}

	// down
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		if (!occupied(i - 1, b, P, oppositeColor) && !(occupied(i - 1, b, P, colorRook)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
			m.src = i - 1;
			m.dst = b;
			Res.insert(m);
		}
		else if (occupied(i - 1, b, P, oppositeColor) && !(pieceType(i - 1, b, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
		{
			m.src = i - 1;
			m.dst = b;
			Res.insert(m);
		}
		else if (occupied(i - 1, b, P, colorRook))
		{
			break;
		}
	}

	return Res;
}

set<mov> legalMovesPawn(Rank r, file f, position P)
{
	bool oc1;	// occupied by opposite color
	bool oc2;	// occupied by the same color

	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorPawn;
	char oppositeColor;

	// defining piece color
	colorPawn = pieceColor(a, b, P);

	if (colorPawn == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';

	// local variables
	set<mov> Res;
	mov m;


	// for White Pawns
	if (colorPawn == 'W')
	{
		// MOVING FORWARD
		if ((0 <= a + 1)&& (a + 1 <= 7) && (0 <= b) && (b <= 7)) {

			// occupied by opposite color
			oc1 = !(occupied(a + 1, b, P, oppositeColor));
			// occupied by the same color
			oc2 = !(occupied(a + 1, b, P, colorPawn));

			// forward by  if not occupied
			if (oc1 && oc2) {
				m.src = a + 1;
				m.dst = b;
				Res.insert(m);
			}
		}

		// FORWARD BY 2 if rank=2 & not occupied
		if ((a == 1) && (0 <= b) && (b <= 7)) {
			oc1 = !(occupied(3, b, P, oppositeColor));
			oc2 = !(occupied(3, b, P, colorPawn));

			// forward to rank=4
			if (oc1 && oc2) {
				m.src = 3;
				m.dst = b;
				Res.insert(m);
			}
		}

		// ATTACK UP & RIGHT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			// occupied by opposite color
			oc1 = (occupied(a + 1, b + 1, P, oppositeColor));

			// attack if opposite color
			if (oc1) {
				m.src = a + 1;
				m.dst = b + 1;
				Res.insert(m);
			}

		}

		// ATTACK UP & LEFT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			// occupied by opposite color
			oc1 = (occupied(a + 1, b - 1, P, oppositeColor));

			// attack if oppsite color
			if (oc1) {
				m.src = a + 1;
				m.dst = b - 1;
				Res.insert(m);
			}

		}

	}


	// for black Pawns
	if (colorPawn == 'B')
	{
		// MOVING DOWN
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b) && (b <= 7)) {

			// not occupied by opposite color
			oc1 = !(occupied(a - 1, b, P, oppositeColor));
			// not occupied by the same color
			oc2 = !(occupied(a - 1, b, P, colorPawn));

			// down if not occupied
			if (oc1 && oc2) {
				m.src = a - 1;
				m.dst = b;
				Res.insert(m);
			}
		}

		// DOWN BY 2 if rank=6 & not occupied
		if ((a == 6) && (0 <= b) && (b <= 7)) {
			oc1 = !(occupied(4, b, P, oppositeColor));
			oc2 = !(occupied(4, b, P, colorPawn));

			// down to rank=3
			if (oc1 && oc2) {
				m.src = 4;
				m.dst = b;
				Res.insert(m);
			}
		}

		// ATTACK DOWN & RIGHT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			// occupied by opposite color
			oc1 = (occupied(a - 1, b + 1, P, oppositeColor));

			// attack if opposite color
			if (oc1) {
				m.src = a - 1;
				m.dst = b + 1;
				Res.insert(m);
			}

		}

		// ATTACK DOWN & LEFT
		if ((0 <= a + 1) && (a + 1 <= 7) && (0 <= b + 1) && (b + 1 <= 7)) {

			// occupied by opposite color
			oc1 = (occupied(a - 1, b - 1, P, oppositeColor));

			// attack if oppsite color
			if (oc1) {
				m.src = a - 1;
				m.dst = b - 1;
				Res.insert(m);
			}

		}

	}


	return Res;
}

set<mov> legalMovesBishop(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorBishop;
	char oppositeColor;

	colorBishop = pieceColor(a, b, P);

	if (colorBishop == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;


	// forward & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			if (!occupied(i + 1, j + 1, P, oppositeColor) && !(occupied(i + 1, j + 1, P, colorBishop)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i + 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			else if (occupied(i + 1, j + 1, P, oppositeColor) && !(pieceType(i + 1, j + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i + 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			else if (occupied(i + 1, j + 1, P, colorBishop))
			{
				break;
			}
		}
	}

	// forward & left
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			if (!occupied(i + 1, j - 1, P, oppositeColor) && !(occupied(i + 1, j - 1, P, colorBishop)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i + 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			else if (occupied(i + 1, j - 1, P, oppositeColor) && !(pieceType(i + 1, j - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i + 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			else if (occupied(i + 1, j - 1, P, colorBishop))
			{
				break;
			}
		}
	}

	// down & left 
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			if (!occupied(i - 1, j - 1, P, oppositeColor) && !(occupied(i - 1, j - 1, P, colorBishop)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i - 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			else if (occupied(i - 1, j - 1, P, oppositeColor) && !(pieceType(i - 1, j - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i - 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			else if (occupied(i - 1, j - 1, P, colorBishop))
			{
				break;
			}
		}
	}

	// down & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			if (!occupied(i - 1, j + 1, P, oppositeColor) && !(occupied(i - 1, j + 1, P, colorBishop)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i - 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			else if (occupied(i - 1, j + 1, P, oppositeColor) && !(pieceType(i - 1, j + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i - 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			else if (occupied(i - 1, j + 1, P, colorBishop))
			{
				break;
			}
		}
	}


	return Res;
}

set<mov> legalMovesQueen(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char colorQueen;
	char oppositeColor;

	colorQueen = pieceColor(a, b, P);

	if (colorQueen == 'W')
		oppositeColor = 'B';
	else
		oppositeColor = 'W';


	set<mov> Res;
	mov m;


	// forward & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied by any color
			if (!occupied(i + 1, j + 1, P, oppositeColor) && !(occupied(i + 1, j + 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i + 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i + 1, j + 1, P, oppositeColor) && !(pieceType(i + 1, j + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i + 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i + 1, j + 1, P, colorQueen))
			{
				break;
			}
		}

		return Res;
	}

	// right
	for (int i = a - 1; i <= 7; ++i) {	// a - 1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied by any color
			if (!occupied(i, j + 1, P, oppositeColor) && !(occupied(i, j + 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i, j + 1, P, oppositeColor) && !(pieceType(i, j + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i, j + 1, P, colorQueen))
			{
				break;
			}
		}
	}

	// forward
	for (int i = a - 1; i <= 7; ++i) {	// a - 1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied by any color
			if (!occupied(i + 1, j, P, oppositeColor) && !(occupied(i + 1, j, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i + 1;
				m.dst = j;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i + 1, j, P, oppositeColor) && !(pieceType(i + 1, j, P) == "K"))
			{
				m.src = i + 1;
				m.dst = j;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i + 1, j, P, colorQueen))
			{
				break;
			}
		}
	}

	// forward & left
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied
			if (!occupied(i + 1, j - 1, P, oppositeColor) && !(occupied(i + 1, j - 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i + 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i + 1, j - 1, P, oppositeColor) && !(pieceType(i + 1, j - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i + 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i + 1, j - 1, P, colorQueen))
			{
				break;
			}
		}
	}

	// left
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied
			if (!occupied(i, j - 1, P, oppositeColor) && !(occupied(i, j - 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i, j - 1, P, oppositeColor) && !(pieceType(i, j - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if cooupied by the same color
			else if (occupied(i, j - 1, P, colorQueen))
			{
				break;
			}
		}
	}

	// down & left 
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied
			if (!occupied(i - 1, j - 1, P, oppositeColor) && !(occupied(i - 1, j - 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i - 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i - 1, j - 1, P, oppositeColor) && !(pieceType(i - 1, j - 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i - 1;
				m.dst = j - 1;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i - 1, j - 1, P, colorQueen))
			{
				break;
			}
		}
	}

	// down
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied
			if (!occupied(i - 1, j, P, oppositeColor) && !(occupied(i - 1, j, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i - 1;
				m.dst = j;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i - 1, j, P, oppositeColor) && !(pieceType(i - 1, j, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i - 1;
				m.dst = j;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i - 1, j, P, colorQueen))
			{
				break;
			}
		}
	}

	// down & right
	for (int i = a - 1; i <= 7; ++i) {	// a -1 index
		for (int j = b - 1; j <= 7; ++j) {
			// if not occupied
			if (!occupied(i - 1, j + 1, P, oppositeColor) && !(occupied(i - 1, j + 1, P, colorQueen)) && !(a > 7) && !(b > 7) && !(a < 0) && !(b < 0)) {
				m.src = i - 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by opposite color
			else if (occupied(i - 1, j + 1, P, oppositeColor) && !(pieceType(i - 1, j + 1, P) == "K"))		// & (pieceColor(i + 1, b, P) != colorQueen)
			{
				m.src = i - 1;
				m.dst = j + 1;
				Res.insert(m);
			}
			// if occupied by the same color
			else if (occupied(i - 1, j + 1, P, colorQueen))
			{
				break;
			}
		}
	}

	return Res;
}




string pieceType(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	string pT;			// piece type 
	pT = P[a][b][1];	// take second letter from the string
	return pT;
}

char pieceColor(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	char col;			// piece type 
	col = P[a][b][0];	// take second letter from the string
	return col;
}

set<mov> legalMoves(Rank r, file f, position P)
{
	int a, b;
	a = int(r) - int('0') - 1;			// make r (rank) integer ('int' to int)
	b = int(f) - int('a');				// make f (file) integer ('char' to int)

	string pT;
	pT = pieceType(a, b, P);


	if (pT == "K")
		return legalMovesKing(a, b, P);

	else if (pT == "b")						 // piece is a bishop
		return legalMovesBishop(r, f, P);

	else if (pT == "k")						 // piece is a knight
		return legalMovesKnight(r, f, P);

	else if (pT == "r")						 // piece is a rook
		return legalMovesRook(r, f, P);

	else if (pT == "Q")					     // piece is a queen
		return legalMovesQueen(r, f, P);

	else if (pT == "p")						 // piece is a pawn
		return legalMovesPawn(r, f, P);


}



// MAJOR FUNCTION
// add checkmate and stalemate
set<mov> simpMoves(position P, color c)
{
	// define sets
	set<mov> Res;
	set<mov> ResOutput;


	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (occupied(i, j, P, c))
				ResOutput = legalMoves(i, j, P);

			Res.insert(ResOutput.begin(), ResOutput.end());		// union of both sets
		}
	}
	return Res;
}
