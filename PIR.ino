void pirHandler() {
  if (millis() - prevPirCheckMillis > PIRCHECKINTERVAL) {
    prevPirCheckMillis = millis();
    if (digitalRead(PIR_PIN) == HIGH && hasSentPIR == false) {
      prevPirOnMillis = millis();
      socketIO_sendPir();
      hasSentPIR = true;
    } else if (hasSentPIR == true && millis() - prevPirOnMillis > PIRSENDINTERVAL) {
      prevPirOnMillis = millis();
      hasSentPIR = false;
    }
  }
}

void fanHandler() {
  if (isFanRunning) {
    if (millis() - currFanRunTime > fan_on_time) {
      isFanRunning = false;
      digitalWrite(FAN_PIN, LOW);
    }
  }
}

void startFan() {
  isFanRunning = true;
  currFanRunTime = millis();
  digitalWrite(FAN_PIN, HIGH);
}
