subtraction :: Int -> Int
subtraction n =
    if mod n 10 == 0 then
        div n 10
    else
        n - 1

read_numbers :: String -> [Int]
read_numbers = map read . words

main =  do
    line <- getLine
    let [n, a] = read_numbers line
    let res = ((iterate subtraction n) !! a)
    print res
