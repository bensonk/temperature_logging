temp <- read.csv("temp.csv")$temp
timestamps <- Sys.time() - (1.1 * length(temp):1)

png("temp.png", width=1200, height=900)
plot(timestamps, temp, type='l', xlab="Time (S)", ylab="Temperature (F)")
dev.off()
