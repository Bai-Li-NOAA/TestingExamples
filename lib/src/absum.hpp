template <class Type>
Type a(Type x, Type y)
{
  Type z = x + y * 0.5;
  return z;
}

template <class Type>
Type b(Type x, Type y)
{
  Type z = x * y * 0.5;
  return z;
}

template <class Type>
Type absum(Type x, Type y)
{
  Type z = a(x, y) + b(x, y);
  return z;
}
