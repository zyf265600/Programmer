import { AuthcheckService } from '../../../guards/authcheck.service';
import { Component } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';
import { Router } from '@angular/router';
import { CanLeave } from 'src/app/guards/unsave.guard';

@Component({
  selector: 'app-secret',
  templateUrl: './secret.component.html',
  styleUrls: ['./secret.component.css']
})
export class SecretComponent implements CanLeave{
  secretPwd: FormGroup = new FormGroup({
    password: new FormControl() 
  });

  constructor(private router: Router, private authCheck: AuthcheckService) { }

  canLeave () {
    return this.secretPwd.get('password')!.dirty;
  }

  onSubmit () {
    this.authCheck.checkPermission(this.secretPwd.value.password);
  }

  clear(){
    
  }

}
