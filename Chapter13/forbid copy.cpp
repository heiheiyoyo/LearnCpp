class Int
{
public:
    Int(const Int&)=delete;
    Int& operator=(const Int&)=delete;
private:
    //Int(const Int&); <- take the same effect
    //Int& operator=(const Int&)
};