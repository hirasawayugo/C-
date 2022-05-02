using System.Runtime.Serialization;

[DataContract]
public struct Vector2D
{
    [DataMember]
    public double X;

    [DataMember]
    public double Y;

    public Vector2D(double x, double y)
    {
        this.X = x;
        this.Y = y;
    }
    //加算
    public static Vector2D Add( Vector2D vec1, Vector2D vec2 )
    {
        Vector2D addVec;
        addVec.X = vec1.X + vec2.X;
        addVec.Y = vec1.Y + vec2.Y;
        return addVec;
    }
    public static Vector2D operator+( Vector2D vec1, Vector2D vec2 )
    {
        return Add(vec1, vec2);
    }
    //内積
    public static double Dot( Vector2D vec1, Vector2D vec2 )
    {
        return (vec1.X * vec2.X) + (vec1.Y * vec2.Y);
    }
}