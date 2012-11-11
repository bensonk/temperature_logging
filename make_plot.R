temp = read.csv("temp.csv")$temp
png("temp.png", width=1200, height=900)
plot(temp, xlab="Time (S)", ylab="Temperature (F)")
dev.off()
