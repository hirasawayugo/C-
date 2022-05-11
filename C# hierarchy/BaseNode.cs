using System;
using System.Collections.Generic;

class BaseNode
{
    protected BaseNode parent;
    protected List<BaseNode> children;
    //ローカル
    protected Vector2D lPos;
    protected double lAngle;
    //グローバル
    protected Vector2D gPos;
    protected double gAngle;

    public BaseNode(){
        parent = null;
        children = new List<BaseNode>();
        lPos = new Vector2D(0,0);
        gPos = new Vector2D(0,0);
        lAngle = 0;
        gAngle = 0;
    }

    public void AddChild( BaseNode child )
    {
        children.Add(child);
        child.parent = this;
    }

    public void Forward( Vector2D vec)
    {
        lPos = vec + lPos;
        Matrix33 mat = Matrix33.Initialize;
        Matrix33.Rotate(mat,(float)this.Angle);
        gPos = mat * lPos;
        if(parent != null ){
            gPos = parent.Pos + gPos;
        }

    }

    public void Rotate( double radian )
    {
        lAngle += radian;
        Matrix33 mat = Matrix33.Initialize;
        Matrix33.Rotate(mat,(float)this.Angle);
        gPos = mat * lPos;
        gPos = parent.Pos + gPos;
        foreach(var child in children)
        {
            child.Rotate(0);
        }
    }

    public Vector2D Pos
    {
        get
        {
            Matrix33 mat =Matrix33.Initialize;
            Matrix33.Rotate(mat,(float)this.Angle);
            Vector2D pos = mat * lPos;
            if(parent != null)
            {
                pos = parent.Pos + pos;
            }
            return pos;
        }
    }
        

    public double Angle
    {
        get
        {
            double pAngle = 0;
            if(parent != null)
            {
                pAngle = parent.Angle;
            }
            gAngle = lAngle + pAngle;
            return gAngle;
        }
        
    }

    public virtual void Log()
    {
        Calculator calc = new Calculator();
        Console.WriteLine("ローカル座標 X:{0:F2} Y:{1:F2}",lPos.X, lPos.Y);
        Console.WriteLine("グローバル座標 X:{0:F2} Y:{1:F2}",gPos.X, gPos.Y);
        Console.WriteLine("ローカル角度：{0:F0}",calc.Degrees(lAngle));
        Console.WriteLine("グローバ角度：{0:F0}",calc.Degrees(gAngle));
    }
}