using  System;
class Tank
{
    private Vector2D pos;
    private Vector2D[] point = new Vector2D[4];
    private double angle;
    private Battery battery;

    double WIDTH;
	double LENGHT;
	double RIGHT;
	double LEFT;
	double FRONT;
	double BACK;
    public Tank(double width, double lenght)
    {
        WIDTH = width;
        LENGHT = lenght;
        RIGHT = WIDTH / 2;
        LEFT = -WIDTH / 2;
        FRONT = LENGHT / 2;
        BACK = -LENGHT / 2;
        SetSidePos();
    }

    public void AddBattery( Battery bat )
    {
        battery = bat;
        battery.UpdatePos(pos);
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
        battery.Rotate(radian);
    }

    public void Forward(double power)
    {
        Vector2D vec = new Vector2D(0, power);
        Matrix33 mat = Matrix33.Initialize;
        
        Matrix33.Rotate(mat, (float)angle);
        Matrix33.Move(mat, vec);
        pos = mat * pos;
        battery.UpdatePos(pos);
    } 

     private void SetSidePos( )
    {
        point[0] = new Vector2D(LEFT, FRONT);
        point[1] = new Vector2D(RIGHT, FRONT);
        point[2] = new Vector2D(RIGHT, BACK);
        point[3] = new Vector2D(LEFT, BACK);
        Matrix33 mat = Matrix33.Initialize;
        Matrix33.Rotate(mat,(float)angle);

        point[0] = mat * point[0];
        point[1] = mat * point[1];
        point[2] = mat * point[2];
        point[3] = mat * point[3];

        Vector2D.Add(point[0],pos);
        Vector2D.Add(point[1],pos);
        Vector2D.Add(point[2],pos);
        Vector2D.Add(point[3],pos);
    }

    public void Debuglog()
    {
        double tAngle = angle * 180 / 3.14;
        Console.WriteLine("戦車 位置 X:{0} Y:{1} 角度:{2}", pos.X, pos.Y, tAngle);
        Console.WriteLine("　　 前左 X:{0} Y:{1} \n　　 前右 X:{2} Y:{3}", point[0].X, point[0].Y,point[1].X, point[1].Y);
        Console.WriteLine("　　 後左 X:{0} Y:{1} \n　　 後ろ右 X:{2} Y:{3}", point[3].X, point[3].Y, point[2].X, point[2].Y);
    }
}