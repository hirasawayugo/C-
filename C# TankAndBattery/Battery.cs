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
}