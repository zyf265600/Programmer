import { Component, OnInit } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';
import { last } from 'rxjs';

@Component({
  selector: 'app-form-method',
  templateUrl: './form-method.component.html',
  styleUrls: ['./form-method.component.css']
})
export class FormMethodComponent implements OnInit{
  form: FormGroup = new FormGroup({
    firstName: new FormControl(),
    lastName: new FormControl(),
  });

  ngOnInit(): void {
    this.form.get('lastName')?.valueChanges.subscribe((value) => {console.log(value)})
  }

  onSubmit() {

  }

  onPatchValue() {
    this.form.patchValue({
      firstName: "😝"
    })
  }

  onSetValue() {
    this.form.setValue({
      firstName: "😝",
      lastName: "😝"
    })
  }

  onReset(){
    this
  }
}
