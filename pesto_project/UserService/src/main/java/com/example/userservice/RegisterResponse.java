package com.example.userservice;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;

public class RegisterResponse {
    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getAuthToken() {
        return authToken;
    }

    public void setAuthToken(String authToken) {
        this.authToken = authToken;
    }

    private String status;
    private String authToken;


}
