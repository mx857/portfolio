package piece;

import main.GamePanel;

public class Queen extends Piece{
    public Queen(int color, int col, int row) {
        super(color, col, row);

        if(color == GamePanel.WHITE){
            image = getImage("/piece/w-queen");
        } else {
            image = getImage("/piece/b-queen");
        }
    }
}

/*She's a Killer Queen
Gunpowder, gelatine
Dynamite with a laser beam
Guaranteed to blow your mind
Anytime*/