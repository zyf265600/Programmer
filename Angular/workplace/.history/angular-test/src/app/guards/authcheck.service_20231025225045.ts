import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {
  private permission: boolean;

  constructor() {
    this.permission = false;
  }

  checkPermission(input: string): void {
    if (input === '12345') {
      this.permission = true;
    } else {
      this.permission = false;
    }
  }

  getPermission(): boolean {
    return this.permission;
  }

}
