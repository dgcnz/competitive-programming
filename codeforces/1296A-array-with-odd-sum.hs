import qualified Data.List as L

solve :: [Int] -> Bool
solve xs
    | odd $ sum xs  = True
    | otherwise = not $ null e || null o
    where
        (e, o) = L.partition even xs 

solvetc :: Int -> IO ()
solvetc 0 = do return ()

solvetc t = do
    n <- getLine
    xs <- getLine
    let ans = solve . map read . words $ xs
    putStrLn $ id (if ans == True then "YES" else "NO")
    solvetc(t - 1)

main = do
    t <- getLine
    solvetc (read t)
    
