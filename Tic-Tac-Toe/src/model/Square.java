package model;

import javafx.scene.shape.Rectangle;

/**
 * Created by Sidney on 2/9/2017.
 */
public class Square {
    private SquareEnum squareEnum;
    Rectangle rectangle;

    public Square(SquareEnum squareEnum) {
        this.squareEnum = squareEnum;
    }

    public SquareEnum getSquareEnum() {
        return squareEnum;
    }
    public void setSquareEnum(SquareEnum squareEnum) {
        this.squareEnum = squareEnum;
    }

    public Rectangle getRectangle() {
        return rectangle;
    }
    public void setRectangle(Rectangle rectangle) {
        this.rectangle = rectangle;
    }
}
