class Piece {
    private:
        int r, c;
    public:
        int row() const { return r;} // returns the row number of this piece
        int column() const { return c;} // returns the column number of this piece
        void place(int Nrow, int Ncol) { // places this piece on the board given a row number and a column number
            this->r = Nrow;
            this->c = Ncol;
        }
        virtual bool menaces(const Piece *p) = 0; // given another piece, returns true if this piece can attack the given piece, and false otherwise
};

// Now write classes for each of the following chess pieces:
class rooks : public virtual Piece { // A rook can move any number of squares horizontally or vertically, but cannot move diagonally.
    public:
        virtual bool menaces(const Piece *p) {
            if ( this->row() == p->row() || this->column() == p->column() ) {
                return true;
            }
            return false;
        }
}; 
class bishop : public virtual Piece { // A bishop can move any number of squares diagonally, but cannot move horizontally or vertically.
    public:
        virtual bool menaces(const Piece *p) {
            if ( abs(this->row() - p->row()) == abs(this->column() - p->column()) ) {
                return true;
            }
            return false;
        }
}; 
class knight : public virtual Piece{ //  A knight can move two spaces in either a horizontal or vertical direction and an additional space in the other direction.
    public:
        virtual bool menaces(const Piece *p) {
            if ( ((abs(this->row() - p->row()) == 2) && (abs(this->column() - p->column()) == 1)) || // if difference in rows is 1 and cols is 2 or other way around, true
            ((abs(this->row() - p->row()) == 1) && (abs(this->column() - p->column()) == 2))) {
                return true;
            }
            return false;
        }
};
class queens : public virtual rooks, bishop { // A queen can move any number of squares horizontally, vertically, or diagonally. Thus, it can move as either a rook or a bishop.
    public:
        virtual bool menaces(const Piece *p) {
            return rooks::menaces(p) || bishop::menaces(p);
        }
};
class amazon : public virtual queens, knight{// An amazon can move either as a queen or as a knight.
    public:
        bool menaces(const Piece *p) {
            return queens::menaces(p) || knight::menaces(p);
        }
};