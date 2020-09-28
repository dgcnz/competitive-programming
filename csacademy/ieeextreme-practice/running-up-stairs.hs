fibs :: [Integer]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

solve :: Int -> Integer
solve n = fibs!!n

main = do
    n <- readLn
    let ans = solve n in print ans
