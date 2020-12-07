void pirHandler() {
  if (millis() - prevPirCheckMillis > PIRCHECKINTERVAL) {
    prevPirCheckMillis = millis();
    if (digitalRead(PIR_PIN) == HIGH && hasSentPIR == false) {
      socketIO_sendPir();
      hasSentPIR = true;
    }
  }
}

void fanHandler() {
  if (isFanRunning) {
    if (millis() - currFanRunTime > FANRUNTIME) {
      isFanRunning = false;
      digitalWrite(FAN_PIN, LOW);
      hasSentPIR = false;
    }
  }
}

void startFan() {
  if (isFanRunning == false) {
    isFanRunning = true;
    currFanRunTime = millis();
    digitalWrite(FAN_PIN, HIGH);
  }
}
