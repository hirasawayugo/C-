using  System;
class Tank
{
    private Vector2D pos;
    private Vector2D frontLeft;
    private Vector2D frontRight;
    private Vector2D backLeft;
    private Vector2D backRight;
    private double angle;
    private Battery bat = new Battery();

    const double WIDTH = 2.0;
	const double LENGHT = 3.0;
	const double RIGHT = WIDTH / 2;
	const double LEFT = -WIDTH / 2;
	const double FRONT = LENGHT / 2;
	const double BACK = -LENGHT / 2;
    public Tank(){
        SetSidePos();
    }
    public Vector2D Pos
    {
        set
        {
            pos = new Vector2D(value.X, value.Y);
        }
        get
        {
            return pos;
        }
    }

    public void Rotate( double radian )
    {
        angle += radian;
        SetSidePos();
        BatRotate(radian);
    }

    public void BatRotate(double radian)
    {
        bat.Rotate(radian);
    }

     private void SetSidePos( )
    {
        frontLeft = new Vector2D(LEFT, FRONT);
        frontRight = new Vector2D(RIGHT, FRONT);
        backLeft = new Vector2D(LEFT, BACK);
        backRight = new Vector2D(RIGHT, BACK);
        Matrix33 mat = Matrix33.Initialize;
        Matrix33.Rotate(mat,(float)angle);

        frontLeft = mat * frontLeft;
        frontRight = mat * frontRight;
        backLeft = mat * backLeft;
        backRight = mat * backRight;

        Vector2D.Add(frontLeft,pos);
        Vector2D.Add(frontRight,pos);
        Vector2D.Add(backLeft,pos);
        Vector2D.Add(backRight,pos);
    }

    public void Debuglog()
    {
        double tAngle = angle * 180 / 3.14;
        Console.WriteLine("戦車 位置 X:{0} Y:{1} 角度:{2}\n", pos.X, pos.Y, tAngle);
        Console.WriteLine("　　 前左 X:{0} Y:{1} \n　　 前右 X:{2} Y:{3}\n", frontLeft.X, frontLeft.Y,frontRight.X, frontRight.Y);
        Console.WriteLine("　　 後左 X:{0} Y:{1} \n　　 後ろ右 X:{2} Y:{3}\n", backLeft.X, backLeft.Y, backRight.X, backRight.Y);
        bat.Debuglog();
    }
}