import { Component, OnInit } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';

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
  }

  onSubmit() {

  }

  onPatchValue() {
    this.form.patchValue({
      first
    })
  }
}
