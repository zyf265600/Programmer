import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {
  private permission: boolean;

  constructor() {
    this.permission = false;
  }

  canCheck(): boolean {
    return this.permission;
  }

  setPermission(input: string): void {
    if (input === '12345') {
      this.permission = true;
    }
    this.permission = this.canCheck(input);
  }

  getPermission(): boolean {
    return this.permission;
  }

}
