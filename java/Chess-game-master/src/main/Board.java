package main;

import java.awt.*;

public class Board {
    final int MAX_COL = 8;
    final int MAX_ROWS = 8;
    public static final int SQUARE_SIZE = 100;
    public static final int HALF_SQUARE_SIZE = SQUARE_SIZE / 2;

    public void draw(Graphics2D g2) {
        int c = 0;

        for(int row = 0; row < MAX_ROWS; row++) {
            for(int col = 0; col < MAX_COL; col++) {
                if(c == 0){
                    g2.setColor(Color.GRAY);
                    c = 1;
                } else if(c == 1){
                    g2.setColor(Color.WHITE);
                    c = 0;
                }

                g2.fillRect(col*SQUARE_SIZE, row*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
            }

            if(c == 0){
                c = 1;
            } else if(c == 1){
                c = 0;
            }

        }
    }
}
