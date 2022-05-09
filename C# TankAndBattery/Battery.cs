using System;
class Battery
{
    private Vector2D pos;
	private Vector2D frontLeft;
	private Vector2D frontRight;
	private Vector2D backLeft;
	private Vector2D backRight;
	private double angle;

    private const double WIDTH = 0.5;
	private const double LENGHT = 1.0;
	private const double RIGHT = WIDTH / 2;
	private const double LEFT = -WIDTH / 2;
	private const double FRONT = LENGHT;
	private const double BACK = 0;

    public Battery()
    {
        UpdatePos(pos);
    }

    public void UpdatePos( Vector2D tPos )
    {
        pos = tPos;
        frontLeft = new Vector2D(LEFT, FRONT);
        frontRight = new Vector2D(RIGHT, FRONT);
        backLeft = new Vector2D(LEFT, BACK);
        backRight = new Vector2D(RIGHT, BACK);
        Matrix33 mat = Matrix33.Initialize;
        Matrix33.Rotate(mat, (float)angle);

        frontLeft = mat * frontLeft;
        frontRight = mat * frontRight;
        backLeft = mat * backLeft;
        backRight = mat * backRight;

        Vector2D.Add(frontLeft, pos);
        Vector2D.Add(frontRight, pos);
        Vector2D.Add(backLeft, pos);
        Vector2D.Add(backRight, pos);
    }

    public void Rotate( double radian )
    {
        angle += radian;
        UpdatePos(pos);
    }

    public void Debuglog()
    {
        double bAngle = angle * 180 / 3.14;
        Console.WriteLine("砲台 位置 X:{0} Y:{1} 角度:{2}\n", pos.X, pos.Y, bAngle);
        Console.WriteLine("　　 前左 X:{0} Y:{1} \n　　 前右 X:{2} Y:{3}\n", frontLeft.X, frontLeft.Y,frontRight.X, frontRight.Y);
        Console.WriteLine("　　 後左 X:{0} Y:{1} \n　　 後ろ右 X:{2} Y:{3}\n", backLeft.X, backLeft.Y, backRight.X, backRight.Y);
    }
}