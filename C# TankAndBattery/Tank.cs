class Tank
{
    private Vector2D pos;
    private Vector2D frontLeft;
    private Vector2D frontRight;
    private Vector2D backLeft;
    private Vector2D backRight;
    private double angle;

    const double WIDTH = 2.0;
	const double LENGHT = 3.0;
	const double RIGHT = WIDTH / 2;
	const double LEFT = -WIDTH / 2;
	const double FRONT = LENGHT / 2;
	const double BACK = -LENGHT / 2;

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
}